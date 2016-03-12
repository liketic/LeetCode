SELECT DISTINCT A.num FROM `Logs` A, `Logs` B, `Logs` C WHERE B.num = A.num AND C.num = A.num AND B.id = A.id + 1 AND C.id = B.id + 1; 
