# Write your MySQL query statement below
select name as Customers
from Customers left join Orders
on Customers.id = Orders.customerID
where Orders.id IS NULL
