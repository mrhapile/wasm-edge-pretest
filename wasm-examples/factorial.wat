(module
  (export "fac" (func $fac))
  (func $fac (param $n i32) (result i32)
    (if (result i32) (i32.eq (local.get $n) (i32.const 0))
      (then (i32.const 1))
      (else
        (i32.mul (local.get $n) (call $fac (i32.sub (local.get $n) (i32.const 1))))
      )
    )
  )
)
