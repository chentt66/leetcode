-- Write your PostgreSQL query statement below
/* JOIN */
-- Write your PostgreSQL query statement below
SELECT customer_id, COUNT(*) count_no_trans
FROM Visits v LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
WHERE t.visit_id IS NULL
GROUP BY customer_id
-- common table expression (CTE)
-- Write your PostgreSQL query statement below
WITH r AS (
    SELECT customer_id, transaction_id
    FROM Visits v LEFT JOIN Transactions t
    ON v.visit_id = t.visit_id
)
SELECT customer_id, COUNT(*) count_no_trans
FROM r
WHERE transaction_id IS NULL
GROUP BY customer_id


/* SYNTAX */
-- Write your PostgreSQL query statement below
SELECT tweet_id FROM Tweets
WHERE CHAR_LENGTH(content) > 15

-- Write your PostgreSQL query statement below
SELECT name FROM Customer
WHERE referee_id <> 2 OR referee_id IS NULL

SELECT COALESCE(
    (SELECT DISTINCT(salary)
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1
    OFFSET 1), NULL)
AS SecondHighestSalary
-- IFNULL() for MySQL

-- date differences
SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM activity
WHERE ('2019-07-27'::date - activity_date) BETWEEN 0 AND 29
GROUP BY activity_date

-- others
-- Write your PostgreSQL query statement below
SELECT teacher_id, COUNT(DISTINCT(subject_id)) AS cnt
FROM Teacher
GROUP BY teacher_id


-- Write your PostgreSQL query statement below
SELECT product_id, year AS first_year, quantity, price
FROM Sales
WHERE (product_id, year) IN
(SELECT product_id, MIN(year) AS first_year
FROM Sales
GROUP BY product_id)
