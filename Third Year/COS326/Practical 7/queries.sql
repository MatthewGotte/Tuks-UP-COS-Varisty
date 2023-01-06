-- TASK 2

-- 2.1
SELECT
	unnest(xpath ('/STAFF[STAFFNO="SL21"]/@branchNo',xml_data) )AS branch_no,
	unnest(xpath ('/STAFF[STAFFNO="SL21"]/STAFFNO/text()',xml_data)) AS staff_no,
	unnest(xpath ('/STAFF[STAFFNO="SL21"]/NAME/FNAME/text()',xml_data) )AS first_name,
	unnest(xpath ('/STAFF[STAFFNO="SL21"]/NAME/LNAME/text()',xml_data) )AS last_name,
	unnest(xpath ('/STAFF[STAFFNO="SL21"]/POSITION/text()',xml_data) )AS position,
	unnest(xpath ('/STAFF[STAFFNO="SL21"]/DOB/text()',xml_data) )AS date_of_birth,
	unnest(xpath ('/STAFF[STAFFNO="SL21"]/SALARY/text()',xml_data) ) AS salary
FROM xml_staff;

-- 2.2
SELECT
	unnest(xpath('/STAFF[@branchNo = "B003"]/NAME/FNAME/text()',xml_data)) AS first_name,
	unnest(xpath('/STAFF[@branchNo = "B003"]/NAME/LNAME/text()',xml_data)) AS last_name,
	unnest(xpath('/STAFF[@branchNo = "B003"]/@branchNo',xml_data)) AS branch_no
FROM xml_staff;

-- 2.3
SELECT
	unnest(xpath ('/STAFF/STAFFNO/text()',xml_data)) AS StaffNo,
	cast(cast(unnest(xpath ('/STAFF/SALARY/text()',xml_data))as text)as integer) AS salary
FROM xml_staff;
