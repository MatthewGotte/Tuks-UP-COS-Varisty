--INSERTS
-- DegreeProgram
INSERT INTO DegreeProgram (code, name, number_of_years, faculty) VALUES ('BSc', 'Bachelor of Science', 3, 'EBIT');
INSERT INTO DegreeProgram (code, name, number_of_years, faculty) VALUES ('BIT', 'Bachelor of IT', 4, 'EBIT');
INSERT INTO DegreeProgram (code, name, number_of_years, faculty) VALUES ('PhD', 'Philosophiae Doctor', 5, 'EBIT');

-- Course
INSERT INTO Course (code, name, department, credits) VALUES ('COS301', 'Software Engineering', 'Computer Science', 40);
INSERT INTO Course (code, name, department, credits) VALUES ('COS326', 'Database Systems', 'Computer Science', 20);
INSERT INTO Course (code, name, department, credits) VALUES ('MTH301', 'Discrete Mathematics', 'Mathematics', 15);
INSERT INTO Course (code, name, department, credits) VALUES ('PHL301', 'Logical', 'Philosophy', 15);


-- Undergraduate
INSERT INTO undergraduate (student_number, title, first_name, last_name, date_of_birth, degree_code, year_of_study, course_registration)
	VALUES ('140010', 'Ms', 'Megan', 'Gotte', '1996-01-01', 'BSc', 3, '{"COS301","COS326","MTH301"}');
INSERT INTO undergraduate (student_number, title, first_name, last_name, date_of_birth, degree_code, year_of_study, course_registration)
    VALUES ('140015', 'Mrs', 'Sue', 'Scholtz', '1995-05-25', 'BSc', 3, '{"COS301","PHL301","MTH301"}' );
INSERT INTO undergraduate (student_number, title, first_name, last_name, date_of_birth, degree_code, year_of_study, course_registration)
    VALUES ('131120', 'Mr', 'Matthew', 'Gotte',  '1995-01-30', 'BIT', 3, '{"COS301","COS326","PHL301"}');
INSERT INTO undergraduate (student_number, title, first_name, last_name, date_of_birth, degree_code, year_of_study, course_registration)
    VALUES ('131140', 'Mnr', 'Cameron', 'Balie',  '1996-02-20', 'BIT', 4, '{"COS301","COS326","MTH301","PHL301"}');

-- Postgraduate
INSERT INTO postgraduate (student_number, title, first_name, last_name, date_of_birth, degree_code, year_of_study, category, supervisor_title, supervisor_first_name, supervisor_last_name)
    VALUES ('101122', 'Mr', 'Tylon', 'Hardenburg', '1987-06-15', 'PhD', 2, 'full_time', 'Dr', 'Linda', 'Marshall');
INSERT INTO postgraduate (student_number, title, first_name, last_name, date_of_birth, degree_code, year_of_study, category, supervisor_title, supervisor_first_name, supervisor_last_name)
    VALUES ('121101', 'Mrs', 'Lauren', 'Balie', '1985-04-27', 'PhD', 3, 'part_time', 'Prof','Martin', 'Olivier');