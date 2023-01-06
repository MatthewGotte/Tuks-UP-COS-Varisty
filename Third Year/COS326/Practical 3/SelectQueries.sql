-- SELECTS
-- 1.
SELECT s.student_id, s.student_number, personFullNames(s), ageInYears(s) FROM Student s;
-- 2.
SELECT u.student_id, u.student_number, personFullNames(u), u.degree_code, u.year_of_study, u.course_registration FROM Undergraduate u;
-- 3.
SELECT pg.student_id, pg.student_number, personFullNames(pg), pg.degree_code, pg.year_of_study, pg.category FROM Postgraduate pg;
-- 4.
SELECT u.student_id, u.student_number, personFullNames(u), u.degree_code, u.year_of_study, u.course_registration FROM Undergraduate u WHERE isFinalYearStudent(u);
-- 5.
SELECT u.student_id, u.student_number, personFullNames(u), u.degree_code, u.year_of_study, u.course_registration FROM Undergraduate u WHERE isRegisteredFor(u, 'COS326');
-- 6.
SELECT pg.student_id, pg.student_number, personFullNames(pg), pg.degree_code, pg.year_of_study, pg.category FROM Postgraduate pg WHERE isFullTime(pg);
-- 7.
SELECT pg.student_id, pg.student_number, personFullNames(pg), pg.degree_code, pg.year_of_study, pg.category FROM Postgraduate pg WHERE isPartTime(pg);