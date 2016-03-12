SELECT c.name FROM Customers c WHERE c.id NOT IN (SELECT DISTINCT CustomerId FROM Orders);

