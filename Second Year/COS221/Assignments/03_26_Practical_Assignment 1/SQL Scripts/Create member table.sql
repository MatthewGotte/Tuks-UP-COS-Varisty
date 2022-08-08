CREATE TABLE `member` (
	`member_id` INTEGER(4) NOT NULL,
	`mem_lname` VARCHAR(45),
    `mem_fname` VARCHAR(45),
    `mem_initial` VARCHAR(4),
    `mem_phone` VARCHAR(10),
    PRIMARY KEY (member_id)
);