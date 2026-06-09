三种遍历的严格递归定义如下：

---

## 核心思想：每个节点被"访问"的时机

对于任意节点 $v$，设其左子树为 $L$、右子树为 $R$：

| 遍历方式 | 访问 $v$ 的时机 | 顺序 |
|---|---|---|
| **Preorder**（前序）| 先于左右子树 | $v \to L \to R$ |
| **Inorder**（中序）| 夹在左右子树之间 | $L \to v \to R$ |
| **Postorder**（后序）| 晚于左右子树 | $L \to R \to v$ |

---

## 递归定义（严格版）

设 `visit(v)` 为"输出节点 $v$"：

```
Preorder(v):
    if v == null: return
    visit(v)          # ← 先访问自己
    Preorder(v.left)
    Preorder(v.right)

Inorder(v):
    if v == null: return
    Inorder(v.left)
    visit(v)          # ← 夹在中间
    Inorder(v.right)

Postorder(v):
    if v == null: return
    Postorder(v.left)
    Postorder(v.right)
    visit(v)          # ← 最后访问自己
```

---

## 用一棵具体树演示

```
        1
       / \
      2   3
     / \
    4   5
```

- **Preorder**：`1 2 4 5 3`（根 → 左子树整体 → 右子树整体）
- **Inorder**：`4 2 5 1 3`（左子树整体 → 根 → 右子树整体）
- **Postorder**：`4 5 2 3 1`（左子树整体 → 右子树整体 → 根）

---

## 几个容易混淆的点

**"pre/in/post"指的是根相对于子树的位置**，不是节点被"碰到"的次数。递归过程中每个节点实际上会被经过三次（下行进入左子树前、从左子树返回后、从右子树返回后），三种遍历的区别仅在于在哪一次经过时才真正"访问"（输出）。

**Inorder 的特殊性**：对于二叉搜索树（BST），inorder 遍历恰好输出有序序列，这是 BST 最重要的性质之一。

**Postorder 的典型用途**：需要先处理完所有子节点再处理父节点的场景——比如计算子树大小、删除树、表达式树求值。

**Preorder 的典型用途**：序列化/反序列化树、从根向下传递信息（如路径问题）。