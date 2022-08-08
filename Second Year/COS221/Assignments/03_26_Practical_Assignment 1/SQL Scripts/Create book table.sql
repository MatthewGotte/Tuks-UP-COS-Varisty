CREATE TABLE `book` (
	`isbn` VARCHAR(17) NOT NULL,
    `book_title` VARCHAR(45),
    `book_author` VARCHAR(45),
    `book_genre` VARCHAR(45),
    `year_published` INTEGER(4),
    PRIMARY KEY (isbn)
);