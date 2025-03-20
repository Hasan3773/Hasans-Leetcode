# Write your MySQL query statement below
SELECT 
t1.name as Employee
FROM Employee t1
JOIN Employee t2 ON t1.salary > t2.salary AND t1.managerID = t2.id;
