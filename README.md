# Examples with WasmEdge Binary Tools

This repository contains example WASM files that can be executed by the WasmEdge binary tools.

## Prerequisites
- `wasmedge` (WasmEdge Runtime)
- `wat2wasm` (WABT - The WebAssembly Binary Toolkit)
- Rust toolchain (for the Hello World example)

## 1. Add Two Numbers (`add.wat`)
The `add.wat` is a handwritten WebAssembly script to add two given numbers.

```bash
wat2wasm add.wat -o add.wasm
wasmedge --reactor add.wasm add 1 2
# Output: 3
```

## 2. Calculate Fibonacci Number (`fibonacci.wat`)
The `fibonacci.wat` computes the Fibonacci sequence. The following example computes the 8th Fibonacci number.

```bash
wat2wasm fibonacci.wat -o fibonacci.wasm
wasmedge --reactor fibonacci.wasm fib 8
# Output: 34
```

## 3. Calculate N Factorial (`factorial.wat`)
The `factorial.wat` computes factorial numbers. The following example computes 12!

```bash
wat2wasm factorial.wat -o factorial.wasm
wasmedge --reactor factorial.wasm fac 12
# Output: 479001600
```

## 4. Hello World (Rust)
The `hello` folder contains a Rust application compiled to WebAssembly.

### Build from Source
First, install the Rust toolchain and the `wasm32-wasip1` target. Then run:

```bash
cd hello
cargo build --offline --release --target=wasm32-wasip1
# The hello.wasm will be located at `target/wasm32-wasip1/release/hello.wasm`
```

### Run in Interpreter Mode
```bash
wasmedge target/wasm32-wasip1/release/hello.wasm WasmEdge 1 2 3
# Output:
# hello
# WasmEdge
# 1
# 2
# 3
```

### Run in AOT Mode
You can also compile the WASM file to a native binary (AOT) for better performance.

```bash
wasmedge compile target/wasm32-wasip1/release/hello.wasm hello.aot.wasm
wasmedge hello.aot.wasm WasmEdge 1 2 3
# Output:
# hello
# WasmEdge
# 1
# 2
# 3
```
