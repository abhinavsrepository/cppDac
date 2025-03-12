#List all employees with there manager names
Select
e.empono,e.ename,m.empno
mgrno,m.ename mgrname
From emp e,emp m
Where e.mgr=m.empno
-- bY JOIN 
 Select
e.empono,e.ename,m.empno
mgrno,m.ename mgrname
From emp e inner join emp m
On e.mgr=m.empno

-- QUESTIONM To display employees along with their manager names, for employees who are working
-- as either salesman or analyst

Select e.empno,e.ename,e.mgr,m.empno
mgrno,m.ename mgrname
From emp e,emp m
Where e.mgr=m.empno and e.job in
(‘salesman’,’analyst’)

-- By Join
Select
e.empono,e.ename,m.empno
mgrno,m.ename mgrname
From emp e inner join emp m
On e.mgr=m.empno


-- List all the student and their course details

Select s.sid,s.sname,c.cid,cname
from student s, Exammarks e.course c
where s.sid= e.sid and e.cid- c.cid;

