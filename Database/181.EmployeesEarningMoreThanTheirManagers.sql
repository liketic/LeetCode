SELECT a.Name FROM Employee a, Employee b WHERE a.ManagerId = b.id AND a.Salary > b.Salary;
