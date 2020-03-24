;;; package --- testing
;;; Author:Justin Kaipada
;;; Commentary:

;;; Code:
(let ((interest 1.6)
      (days 31)
      (principle 10000))
  (* (* (/ (* principle 3) 100) days) (/ (* (/ interest 100) 12) 365))
  )

;;; hello_maths.el ends here
