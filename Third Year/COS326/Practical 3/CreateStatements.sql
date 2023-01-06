-- CREATES

-- a.
-- create ENUM for titles
CREATE TYPE student_titles AS ENUM(
	'Ms', 'Mev', 'Miss', 'Mrs', 'Mr', 'Mnr'
);

CREATE TYPE supervisor_titles AS ENUM(
	'Ms', 'Mev', 'Miss', 'Mrs', 'Mr', 'Mnr', 'Dr', 'Prof'
);

CREATE TYPE CATEGORY AS ENUM (
	'part_time', 'full_time'
);

-- DOMAINS 
CREATE DOMAIN student_number AS varchar(6) CHECK (
    VALUE ~ '\d{6}$'
);



-- b.
-- create sequence for Student
CREATE SEQUENCE student_key
START 0
INCREMENT 1
MINVALUE 0;

CREATE SEQUENCE course_key
START 0
INCREMENT 1
MINVALUE 0;


CREATE SEQUENCE degree_key
START 0
INCREMENT 1
MINVALUE 0;



-- c.
-- create Student table
CREATE TABLE Student(
	student_id int DEFAULT nextval('student_key') NOT NULL,
	student_number student_number NOT NULL,
	title student_titles,
	first_name varchar,
	last_name varchar,
	date_of_birth date,
	degree_code varchar,
	year_of_study int,
	PRIMARY KEY (student_id)
);

-- create Undergraduate table - inherit Student
CREATE TABLE Undergraduate(
	course_registration varchar[]
) inherits (Student);

-- create Postgraduate table - inherit Student
CREATE TABLE Postgraduate(
	category CATEGORY,
	supervisor_title supervisor_titles,
	supervisor_first_name varchar,
	supervisor_last_name varchar
) inherits (Student);

-- DEGREE PROGRAM
CREATE TABLE DegreeProgram (
    degree_key INTEGER DEFAULT nextval('degree_key') NOT NULL,
    code varchar NOT NULL,
    name varchar NOT NULL,
    number_of_years INTEGER NOT NULL,
	faculty varchar NOT NULL,
    PRIMARY KEY (degree_key)
);

-- COURSE
CREATE TABLE Course (
    course_key INTEGER DEFAULT nextval('course_key') NOT NULL,
	code varchar NOT NULL,
    name varchar NOT NULL,
    department varchar NOT NULL,
    credits INTEGER NOT NULL,
    PRIMARY KEY (course_key)
);



-- d.

-- functions for Student
-- personFullNames
CREATE OR REPLACE FUNCTION personFullNames(s Student) RETURNS text AS
$$
BEGIN
    RETURN CONCAT(s.title, ' ', s.first_name, ' ', s.last_name);
END
$$ LANGUAGE plpgsql;

-- ageInYears
CREATE OR REPLACE FUNCTION ageInYears(s Student) RETURNS int AS
$$
BEGIN
    RETURN CAST(EXTRACT(YEAR from AGE(s.date_of_birth)) AS int);
END
$$ LANGUAGE plpgsql;

-- functions for Undergraduate
-- isFinalYearStudent
CREATE OR REPLACE FUNCTION isFinalYearStudent(ug Undergraduate) RETURNS boolean AS
$$
BEGIN
    RETURN (ug.year_of_study = (SELECT (number_of_years) FROM DegreeProgram WHERE code = ug.degree_code));
END
$$ LANGUAGE plpgsql;

-- isRegisteredFor
CREATE OR REPLACE FUNCTION isRegisteredFor(u undergraduate, course text) RETURNS boolean AS
$$
BEGIN
    RETURN (course = ANY(u.course_registration));
END
$$ LANGUAGE plpgsql;

-- functions for Postgraduate
-- personFullNames
CREATE OR REPLACE FUNCTION personFullNames(pg Postgraduate) RETURNS text AS
$$
BEGIN
    RETURN (CONCAT(pg.supervisor_title, ' ', pg.supervisor_first_name, ' ', pg.supervisor_last_name));
END
$$ LANGUAGE plpgsql;
	
-- isPartTime
CREATE OR REPLACE FUNCTION isPartTime(pg Postgraduate) RETURNS boolean AS
$$
BEGIN
    RETURN (pg.category = 'part_time');
END
$$ LANGUAGE plpgsql;

-- isFullTime
CREATE OR REPLACE FUNCTION isFullTime(pg Postgraduate) RETURNS boolean AS
$$
BEGIN
    RETURN (pg.category = 'full_time');
END
$$ LANGUAGE plpgsql;