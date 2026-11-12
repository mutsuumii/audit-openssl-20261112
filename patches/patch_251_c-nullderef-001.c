# Missing NULL check after allocation
# CWE-476 | Severity: HIGH
# File: crypto/ct/ct_sct_ctx.c line 229

**Risk:** Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
