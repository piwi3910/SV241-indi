# Ghidra script to export decompiled functions
# Run with: analyzeHeadless ... -postScript ExportDecompiled.py

from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
import os

# Initialize decompiler
decomp = DecompInterface()
decomp.openProgram(currentProgram)

output_dir = os.path.dirname(str(currentProgram.getExecutablePath()))
output_file = os.path.join(output_dir, "decompiled_functions.c")

# Get all functions
fm = currentProgram.getFunctionManager()
funcs = fm.getFunctions(True)

with open(output_file, 'w') as f:
    f.write("// Decompiled ESP32 SV241 Firmware\n")
    f.write("// Processor: Xtensa (ESP32)\n\n")
    
    for func in funcs:
        # Decompile each function
        results = decomp.decompileFunction(func, 30, ConsoleTaskMonitor())
        if results and results.decompileCompleted():
            decomp_func = results.getDecompiledFunction()
            if decomp_func:
                c_code = decomp_func.getC()
                f.write("// Function at 0x{:08x}\n".format(func.getEntryPoint().getOffset()))
                f.write(c_code)
                f.write("\n\n")
                
print("Decompiled output written to: " + output_file)
