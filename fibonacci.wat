(module
  (func $fib (param $n i32) (result i32)
    (if (result i32)
      (i32.le_s (local.get $n) (i32.const 2))
      (then (i32.const 1))
      (else
        (i32.add
          (call $fib
            (i32.sub (local.get $n) (i32.const 1)))
          (call $fib
            (i32.sub (local.get $n) (i32.const 2)))))
    )
  )
  (export "fib" (func $fib))
)
