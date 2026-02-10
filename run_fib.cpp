#include <wasmedge/wasmedge.h>
#include <stdio.h>

int main() {
    WasmEdge_ConfigureContext *Conf = WasmEdge_ConfigureCreate();
    WasmEdge_ConfigureAddHostRegistration(
        Conf, WasmEdge_HostRegistration_Wasi);

    WasmEdge_VMContext *VM = WasmEdge_VMCreate(Conf, NULL);

    WasmEdge_Value Params[1];
    Params[0] = WasmEdge_ValueGenI32(8);

    WasmEdge_Value Returns[1];


    WasmEdge_String FuncName = WasmEdge_StringCreateByCString("fib");
    WasmEdge_Result Res = WasmEdge_VMRunWasmFromFile(
        VM,
        "fibonacci.wasm",
        FuncName,
        Params,
        1,
        Returns,
        1
    );
    WasmEdge_StringDelete(FuncName);
    if (!WasmEdge_ResultOK(Res)) {
        printf("Execution failed: %s\n",
               WasmEdge_ResultGetMessage(Res));
        WasmEdge_VMDelete(VM);
        WasmEdge_ConfigureDelete(Conf);
        return 1;
    }

    int32_t Result = WasmEdge_ValueGetI32(Returns[0]);
    printf("fib(8) = %d\n", Result);

    WasmEdge_VMDelete(VM);
    WasmEdge_ConfigureDelete(Conf);

    return 0;
}
