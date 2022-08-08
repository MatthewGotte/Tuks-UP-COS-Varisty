INSERT INTO `borrowed` (
	`borrowed_id`,
    `isbn`,
    `member_id`,
    `taken_date`
)
VALUES
	(1110,(SELECT isbn FROM book WHERE isbn = '978-0345391803'),(SELECT member_id FROM member WHERE member_id = '1013'),'2021-02-10'),
    (1112,(SELECT isbn FROM book WHERE isbn = '9780241257265'),(SELECT member_id FROM member WHERE member_id = '1018'),'2021-02-15'),
    (1113,(SELECT isbn FROM book WHERE isbn = '9781250010292'),(SELECT member_id FROM member WHERE member_id = '1016'),'2021-02-12'),
    (1114,(SELECT isbn FROM book WHERE isbn = '9780330241182'),(SELECT member_id FROM member WHERE member_id = '1010'),'2021-02-20'),
    (1115,(SELECT isbn FROM book WHERE isbn = '978-0-7981-8166-2'),(SELECT member_id FROM member WHERE member_id = '1016'),'2021-02-22'),
    (1116,(SELECT isbn FROM book WHERE isbn = '9781841351414'),(SELECT member_id FROM member WHERE member_id = '1012'),'2021-02-26'),
    (1117,(SELECT isbn FROM book WHERE isbn = '9781439149034'),(SELECT member_id FROM member WHERE member_id = '1019'),'2021-02-05'),
    (1118,(SELECT isbn FROM book WHERE isbn = '978-0307474278'),(SELECT member_id FROM member WHERE member_id = '1018'),'2021-02-10'),
    (1111,(SELECT isbn FROM book WHERE isbn = '9780451532244'),(SELECT member_id FROM member WHERE member_id = '1010'),'2021-02-14')
