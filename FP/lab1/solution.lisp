
(defun fast* (a b)
    (if (or (= a 0) (= b 0))
        0
        (if (= b 1)
            a
            (if (= b (- 1))
                (- a)
                (if (< b 0)
                    (- (fast* a (- b)))
                    (if (= (mod b 2) 1)
                        (+ a (fast* a (- b 1)))
                        (* 2 (fast* a (/ b 2)))))))))
