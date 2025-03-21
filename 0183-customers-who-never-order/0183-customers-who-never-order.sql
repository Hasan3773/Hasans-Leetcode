# Write your MySQL query statement below
# one table of customers and one of order
# FInd customers who dont order, outer join?
SELECT
Customers.name AS Customers
FROM Customers
LEFT JOIN Orders ON Orders.customerID = Customers.id
WHERE Orders.id IS NULL;