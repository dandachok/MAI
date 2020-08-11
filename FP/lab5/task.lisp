(defvar *tolerance* 0.001)

(defclass cart ()
 ((x :initarg :x :reader x)
  (y :initarg :y :reader y)))

(defclass polar ()
 ((radius :initarg :radius :accessor radius)
  (angle  :initarg :angle  :accessor angle)))

(defmethod cart-x ((p polar))
  (* (radius p) (cos (angle p))))

(defmethod cart-y ((p polar))
  (* (radius p) (sin (angle p))))

(defgeneric to-cart (arg)
 (:method ((c cart))
  c)
(:method ((p polar))
  (make-instance 'cart :x (cart-x p) :y (cart-y p))))

(defmethod on-line-p ((c cart) x1 y1 x2 y2)
  (let ((a1 (- x1 x2)) (a2 (- y1 y2)))
    (cond ((< (abs a1) *tolerance*) (< (abs (- (x c) x1)) *tolerance*))
          ((< (abs a2) *tolerance*) (< (abs (- (y c) y1)) *tolerance*))
          (T (< (abs (- (/ (- (x c) x1) a1) (/ (- (y c) y1) a2))) *tolerance*)))))

(defun on-single-line-p (vertices)
    (let ((x1 (x (to-cart (first vertices)))) 
          (y1 (y (to-cart (first vertices))))
          (x2 (x (to-cart (second vertices))))
          (y2 (y (to-cart (second vertices)))))
      (loop for point in vertices
        do (if (not (on-line-p (to-cart point) x1 y1 x2 y2))
          (return-from on-single-line-p NIL)))
    T))