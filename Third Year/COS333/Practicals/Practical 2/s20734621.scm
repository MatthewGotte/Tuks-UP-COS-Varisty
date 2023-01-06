(define (coneArea radius height)
    (let ((pi (/ 22 7)))
        (if (and (> radius 0) (> height 0))
            (* pi (* (* radius radius) (/ height 3))) 
                0)))

(define countNegatives
    (lambda (arr)
        (cond
            ((null? arr) 0)
            ((< (car arr) 0) (+ 1 (countNegatives (cdr arr))))
            (else (countNegatives (cdr arr)))
        )
    )
)

(define getEveryOddElement
    (lambda (arr)
        (cond 
            ((null? arr) arr)
            ((null? (cdr arr)) arr)
            (else (cons (car arr) (getEveryOddElement (cddr arr))))
        )
    )
)