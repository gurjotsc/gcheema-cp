# Write your MySQL query statement below
select name from Employee as t1 join
                                (
                                    select managerId from Employee
                                    group by ManagerId Having Count(ManagerId) >= 5
                                ) as t2
on t1.Id = t2.ManagerId;