# Write your MySQL query statement below
select c.name from Customers c where c.id not in (select distinct CustomerId from Orders);

