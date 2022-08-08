CREATE TABLE `borrowed` (
  `borrowed_id` INT(4) NOT NULL,
  `isbn` VARCHAR(17),
  `member_id` INT(4),
  `taken_date` DATE,
  PRIMARY KEY (borrowed_id),
  CONSTRAINT `isbn`
    FOREIGN KEY (`isbn`)
    REFERENCES `u20734621_librarysystem`.`book` (`isbn`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `member_id`
    FOREIGN KEY (`member_id`)
    REFERENCES `u20734621_librarysystem`.`member` (`member_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE
);