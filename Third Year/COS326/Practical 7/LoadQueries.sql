-- create table for xml_staff_list
CREATE TABLE xml_staff_list(
	filename varchar NOT NULL,
	xml_document xml NOT NULL,
	PRIMARY KEY (filename)
);

-- insert values into xml_staff_list
INSERT INTO xml_staff_list (filename, xml_document) VALUES ('staff_list.xml', CAST(pg_read_file('./MyXMLfiles/staff_list.xml') AS xml));
	
	
	
	
-- create table for xml_staff
CREATE TABLE xml_staff(
	entry_number int NOT NULL,
	xml_data xml NOT NULL,
	PRIMARY KEY (entry_number)
);

-- insert function for xml_staff
create or replace function loadStaffnodes(xp text, arg xml) returns boolean AS
$$
declare
	flag boolean := false;
begin

	for i in 1..2 loop
		insert into xml_staff(entry_number, xml_data)
		values(i,unnest(xpath(xp || '[' || i || ']',arg)));
		flag := true;
	end loop;
	return flag;

end;
$$ language plpgsql;

-- populate xml_staff with the function
SELECT loadStaffnodes('./STAFFLIST/STAFF', xml_document) FROM xml_staff_list;




-- create table for shred_staff_list
CREATE TABLE shred_staff_list(
	branch_no varchar,
	staff_no varchar,
	first_name varchar,
	last_name varchar,
	position varchar,
	date_of_birth varchar,
	salary varchar,
    PRIMARY KEY(staff_no)
);

-- insert function for shred_staff_list
create or replace function loadChildrenNodes(xp text, arg xml) returns boolean AS
$$
declare
	flag boolean := false;
begin
	for i in 1..2 loop
		insert into shred_staff_list(branch_no, staff_no, first_name, last_name, position, date_of_birth, salary)
		values(
			unnest(xpath(xp || '[' || i || ']/@branchNo', arg)),
			unnest(xpath(xp || '[' || i || ']/STAFFNO/text()', arg)),
			unnest(xpath(xp || '[' || i || ']/NAME/FNAME/text()', arg)),
			unnest(xpath(xp || '[' || i || ']/NAME/LNAME/text()', arg)),
			unnest(xpath(xp || '[' || i || ']/POSITION/text()', arg)),
			unnest(xpath(xp || '[' || i || ']/DOB/text()', arg)),
			unnest(xpath(xp || '[' || i || ']/SALARY/text()', arg))
		);
		flag := true;
	end loop;
	return flag;
end;
$$ language plpgsql;

-- populate shred_staff_list with function
SELECT loadChildrenNodes('./STAFFLIST/STAFF', xml_document) FROM xml_staff_list;


-- SELECT * FROM xml_staff_list
-- SELECT * FROM xml_staff
-- SELECT * FROM shred_staff_list