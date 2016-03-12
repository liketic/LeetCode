SELECT D.name AS Department, E.name AS Employee, E.Salary AS Salary FROM Employee E, Department D
WHERE E.DepartmentId = D.Id AND E.Salary = (SELECT max(Salary) FROM Employee WHERE DepartmentId = E.DepartmentId);


