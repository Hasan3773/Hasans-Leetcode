# Write your MySQL query statement below
WITH Ranked AS (
    SELECT 
    salary,
    DENSE_RANK() OVER (ORDER BY salary DESC) AS ordering
    FROM Employee
)
SELECT COALESCE(
    (SELECT DISTINCT salary 
    FROM Ranked WHERE ordering = 2
    ), NULL)
AS SecondHighestSalary
