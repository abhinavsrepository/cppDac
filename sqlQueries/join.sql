select empno,ename,sal,location
from emp_india
union
select empno,ename,null,location
from emp_us
union
select empno,ename,null,location
from emp_japan;