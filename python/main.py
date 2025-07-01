import ctypes
import os


# === Load DLL ===

lib_path = os.path.abspath("bin/libadvm.dll")

lib = ctypes.CDLL(lib_path)

# Define function signature
lib.advm_add.argtypes = [ctypes.c_int32, ctypes.c_int32]
lib.advm_add.restype = ctypes.c_int32

# === Gọi hàm ===
a: ctypes.c_int32 = 42
b: ctypes.c_int32 = -19
result = lib.advm_add(a, b)
print(f"{a} + {b} = {result}")
