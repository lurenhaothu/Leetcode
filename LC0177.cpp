CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
SELECT DISTINCT salary AS getNthHighestSalary
      FROM (
          SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) AS salaryRank FROM EMPLOYEE
      ) AS sub
      WHERE salaryRank=N
  );
END
