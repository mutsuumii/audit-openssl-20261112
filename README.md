# Security audit: openssl/openssl

Date: 2026-11-12 | Auditor: [mutsuumii](https://github.com/mutsuumii)

## Summary

Found 474 issue(s): 26 critical, 448 high.

## Findings

### 1. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/cmp/cmp_server.c` line 45

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(srv_ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 2. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/cmp/cmp_server.c` line 62

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_CMP_SRV_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 3. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/cmp/cmp_server.c` line 197

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_CMP_PKISI_free(si);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 4. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/cmp/cmp_server.c` line 301

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_CMP_PKISI_free(si);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 5. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/cmp/cmp_server.c` line 302

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(certOut);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 6. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/cmp/cmp_server.c` line 304

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_STACK_OF_X509_free(chainOut);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 7. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/cmp/cmp_server.c` line 305

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_STACK_OF_X509_free(caPubs);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 8. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/cmp/cmp_server.c` line 348

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_CRMF_CERTID_free(certId);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 9. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/cmp/cmp_server.c` line 349

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_CMP_PKISI_free(si);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 10. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/cmp/cmp_server.c` line 538

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_CMP_MSG_free(orig_req);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 11. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/cmp/cmp_server.c` line 589

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(tid_str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 12. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/cmp/cmp_server.c` line 590

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(ctx_str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 13. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/cmp/cmp_server.c` line 740

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_CMP_PKISI_free(si);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 14. [HIGH] Use-after-free pattern

**CWE-416** | `test/testutil/fake_random.c` line 47

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(vrng);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 15. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `demos/http3/ossl-nghttp3-demo-server.c` line 772

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(filename, h3ssl->fileprefix);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 16. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `demos/http3/ossl-nghttp3-demo-server.c` line 773

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(filename, h3ssl->url);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 17. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `demos/http3/ossl-nghttp3-demo-server.c` line 802

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(filename, h3ssl->fileprefix);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 18. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `demos/http3/ossl-nghttp3-demo-server.c` line 803

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(filename, h3ssl->url);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 19. [CRITICAL] Format string vulnerability

**CWE-134** | `demos/http3/ossl-nghttp3-demo-server.c` line 133

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf("Oops too many streams to add!!!\n");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 20. [CRITICAL] Format string vulnerability

**CWE-134** | `demos/http3/ossl-nghttp3-demo-server.c` line 336

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf("on_end_stream!\n");
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 21. [CRITICAL] Format string vulnerability

**CWE-134** | `demos/http3/ossl-nghttp3-demo-server.c` line 375

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf("nghttp3_conn_read_stream used %d of %d on %llu\n", r,
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 22. [CRITICAL] Format string vulnerability

**CWE-134** | `demos/http3/ossl-nghttp3-demo-server.c` line 380

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf("nghttp3_conn_read_stream used %d of %d (not fatal) on %llu\n", r,
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 23. [CRITICAL] Format string vulnerability

**CWE-134** | `demos/http3/ossl-nghttp3-demo-server.c` line 830

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf("step_read_data for %s %zu\n", h3ssl->url, h3ssl->ldata);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 24. [CRITICAL] Format string vulnerability

**CWE-134** | `demos/http3/ossl-nghttp3-demo-server.c` line 1209

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf("nghttp3_conn_writev_stream done: %ld stream: %llu fin %d\n",
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 25. [CRITICAL] Format string vulnerability

**CWE-134** | `demos/http3/ossl-nghttp3-demo-server.c` line 1214

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf("Sending end data on %llu fin %d\n",
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 26. [CRITICAL] Format string vulnerability

**CWE-134** | `demos/http3/ossl-nghttp3-demo-server.c` line 1224

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
printf("nghttp3_conn_writev_stream: %ld fin: %d\n", (long int)sveccnt, fin);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 27. [HIGH] Use-after-free pattern

**CWE-416** | `demos/http3/ossl-nghttp3-demo-server.c` line 456

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(rstream);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 28. [HIGH] Use-after-free pattern

**CWE-416** | `demos/http3/ossl-nghttp3-demo-server.c` line 457

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(pstream);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 29. [HIGH] Use-after-free pattern

**CWE-416** | `demos/http3/ossl-nghttp3-demo-server.c` line 458

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(cstream);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 30. [HIGH] Use-after-free pattern

**CWE-416** | `demos/http3/ossl-nghttp3-demo-server.c` line 543

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(oldconn);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 31. [HIGH] Use-after-free pattern

**CWE-416** | `demos/http3/ossl-nghttp3-demo-server.c` line 810

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(res);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 32. [HIGH] Use-after-free pattern

**CWE-416** | `demos/http3/ossl-nghttp3-demo-server.c` line 932

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 33. [HIGH] Use-after-free pattern

**CWE-416** | `demos/http3/ossl-nghttp3-demo-server.c` line 1321

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 34. [HIGH] Use-after-free pattern

**CWE-416** | `demos/http3/ossl-nghttp3-demo-server.c` line 1332

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(listener);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 35. [HIGH] Use-after-free pattern

**CWE-416** | `demos/http3/ossl-nghttp3-demo-server.c` line 1377

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 36. [HIGH] Missing NULL check after allocation

**CWE-476** | `demos/http3/ossl-nghttp3-demo-server.c` line 805

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
res = malloc(size + 1);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 37. [HIGH] Missing NULL check after allocation

**CWE-476** | `demos/http3/ossl-nghttp3-demo-server.c` line 1173

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
h3ssl.ptr_data = (uint8_t *)malloc(4096);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 38. [HIGH] Use-after-free pattern

**CWE-416** | `test/clienthellotest.c` line 67

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 39. [HIGH] Use-after-free pattern

**CWE-416** | `test/clienthellotest.c` line 87

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(rbio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 40. [HIGH] Use-after-free pattern

**CWE-416** | `test/clienthellotest.c` line 88

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(wbio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 41. [HIGH] Use-after-free pattern

**CWE-416** | `test/clienthellotest.c` line 146

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(con);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 42. [HIGH] Use-after-free pattern

**CWE-416** | `test/clienthellotest.c` line 147

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 43. [HIGH] Use-after-free pattern

**CWE-416** | `test/clienthellotest.c` line 148

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_SESSION_free(sess);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 44. [HIGH] Use-after-free pattern

**CWE-416** | `test/clienthellotest.c` line 149

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(sessbio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 45. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 126

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(port);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 46. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 139

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(port);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 47. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 225

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_CIPHER_free(cipher);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 48. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 229

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(token_key);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 49. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 506

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
*     @c SSL_free(user_ssl) cascades through @c ossl_quic_free() ->
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 50. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 581

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(tls);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 51. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 582

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(user_ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 52. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 631

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ossl_qrx_free(qrx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 53. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 681

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ossl_quic_channel_free(ch);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 54. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 682

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(user_ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 55. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 747

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ossl_quic_channel_free(ch);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 56. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 765

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ossl_quic_channel_free(ch);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 57. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 766

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(tls);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 58. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 768

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(user_ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 59. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 919

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ossl_quic_channel_free(ch);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 60. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 931

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ossl_quic_channel_free(ch);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 61. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 940

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ossl_quic_channel_free(ch);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 62. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 1051

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BUF_MEM_free(buf_mem);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 63. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 1069

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BUF_MEM_free(buf_mem);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 64. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 1074

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BUF_MEM_free(buf_mem);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 65. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 1585

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(remote_addr);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 66. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 1614

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(ct_buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 67. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 1628

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(ct_buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 68. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 1919

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ossl_qrx_free(qrx); /* releases reference */
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 69. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_port.c` line 1920

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ossl_qrx_free(qrx_src);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 70. [HIGH] Use-after-free pattern

**CWE-416** | `apps/genpkey.c` line 119

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 71. [HIGH] Use-after-free pattern

**CWE-416** | `apps/genpkey.c` line 317

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
sk_OPENSSL_STRING_free(keyopt);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 72. [HIGH] Use-after-free pattern

**CWE-416** | `apps/genpkey.c` line 334

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
sk_OPENSSL_STRING_free(encopt);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 73. [HIGH] Use-after-free pattern

**CWE-416** | `apps/genpkey.c` line 335

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_free(pkey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 74. [HIGH] Use-after-free pattern

**CWE-416** | `apps/genpkey.c` line 336

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 75. [HIGH] Use-after-free pattern

**CWE-416** | `apps/genpkey.c` line 337

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_CIPHER_free(cipher);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 76. [HIGH] Use-after-free pattern

**CWE-416** | `apps/genpkey.c` line 340

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(pass);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 77. [HIGH] Use-after-free pattern

**CWE-416** | `apps/genpkey.c` line 341

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NCONF_free(conf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 78. [HIGH] Use-after-free pattern

**CWE-416** | `apps/genpkey.c` line 363

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(pbio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 79. [HIGH] Use-after-free pattern

**CWE-416** | `apps/genpkey.c` line 375

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_free(pkey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 80. [HIGH] Use-after-free pattern

**CWE-416** | `apps/genpkey.c` line 382

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 81. [HIGH] Use-after-free pattern

**CWE-416** | `apps/genpkey.c` line 383

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_free(pkey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 82. [HIGH] Use-after-free pattern

**CWE-416** | `apps/genpkey.c` line 416

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 83. [HIGH] Use-after-free pattern

**CWE-416** | `demos/quic/server/server.c` line 75

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 84. [HIGH] Use-after-free pattern

**CWE-416** | `demos/quic/server/server.c` line 184

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(conn);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 85. [HIGH] Use-after-free pattern

**CWE-416** | `demos/quic/server/server.c` line 189

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(conn);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 86. [HIGH] Use-after-free pattern

**CWE-416** | `demos/quic/server/server.c` line 197

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(listener);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 87. [HIGH] Use-after-free pattern

**CWE-416** | `demos/quic/server/server.c` line 237

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 88. [CRITICAL] Format string vulnerability

**CWE-134** | `ssl/t1_lib.c` line 1399

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
if (ossl_asprintf(&restored_default_group_string,
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 89. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 126

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ssl3_free(s);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 90. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 363

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_KEYMGMT_free(keymgmt);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 91. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 665

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_KEYMGMT_free(keymgmt);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 92. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 958

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(a);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 93. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 1003

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(gix);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 94. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 1174

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(glist);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 95. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 1175

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(kslist);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 96. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 1176

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(tpllist);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 97. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 1416

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(restored_default_group_string);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 98. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 1728

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(restored_tuple_string);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 99. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 2364

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_CTX_free(pctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 100. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 2426

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(cache);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 101. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 2427

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(tls12_sigalgs_list);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 102. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 2428

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_free(tmpkey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 103. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 2455

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_free(hash);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 104. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 2468

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_CTX_free(pctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 105. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 2481

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(retval);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 106. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 2482

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_free(tmpkey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 107. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 2485

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(retval);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 108. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 2494

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_free(tmpkey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 109. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 3324

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(sdec);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 110. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 3329

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(sdec);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 111. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 3338

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(sdec);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 112. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 3342

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_SESSION_free(sess);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 113. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 3370

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_CIPHER_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 114. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 3399

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_SESSION_free(sess);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 115. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 3407

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_SESSION_free(sess);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 116. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 3681

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 117. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 4073

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(sigalgs);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 118. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 4518

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_PARAM_free(params);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 119. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 4519

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_PARAM_BLD_free(tmpl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 120. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 4520

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_CTX_free(pctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 121. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/t1_lib.c` line 4521

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(p);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 122. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 276

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ginf->tlsname = OPENSSL_strdup(p->data);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 123. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 285

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ginf->realname = OPENSSL_strdup(p->data);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 124. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 301

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ginf->algorithm = OPENSSL_strdup(p->data);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 125. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 449

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sinf->sigalg_name = OPENSSL_strdup(p->data);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 126. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 459

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sinf->name = OPENSSL_strdup(p->data);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 127. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 486

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sinf->sigalg_oid = OPENSSL_strdup(p->data);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 128. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 498

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sinf->sig_name = OPENSSL_strdup(p->data);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 129. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 510

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sinf->sig_oid = OPENSSL_strdup(p->data);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 130. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 522

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sinf->hash_name = OPENSSL_strdup(p->data);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 131. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 534

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sinf->hash_oid = OPENSSL_strdup(p->data);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 132. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 546

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sinf->keytype = OPENSSL_strdup(p->data);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 133. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 558

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sinf->keytype_oid = OPENSSL_strdup(p->data);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 134. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 718

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ctx->ssl_cert_info = OPENSSL_calloc(ctx->sigalg_list_len, sizeof(lu));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 135. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 1718

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
restored_tuple_string = OPENSSL_malloc(len + 1 /* \0 */);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 136. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 2326

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
cache = OPENSSL_calloc(sigalgs_len, sizeof(const SIGALG_LOOKUP));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 137. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 2330

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
tls12_sigalgs_list = OPENSSL_calloc(sigalgs_len, sizeof(uint16_t));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 138. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 2496

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
retval = OPENSSL_strdup("");
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 139. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 3074

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
s->s3.tmp.valid_flags = OPENSSL_calloc(s->ssl_pkey_num, sizeof(uint32_t));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 140. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/t1_lib.c` line 3322

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sdec = OPENSSL_malloc(eticklen);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 141. [HIGH] Use-after-free pattern

**CWE-416** | `test/asn1_string_test.c` line 161

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_STRING_free(abs);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 142. [HIGH] Use-after-free pattern

**CWE-416** | `test/asn1_string_test.c` line 380

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_BIT_STRING_free(abs);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 143. [HIGH] Use-after-free pattern

**CWE-416** | `test/asn1_string_test.c` line 404

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_STRING_clear_free(tmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 144. [HIGH] Use-after-free pattern

**CWE-416** | `test/asn1_string_test.c` line 425

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_STRING_clear_free(tmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 145. [HIGH] Use-after-free pattern

**CWE-416** | `test/asn1_string_test.c` line 454

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_STRING_clear_free(tmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 146. [HIGH] Use-after-free pattern

**CWE-416** | `test/asn1_string_test.c` line 472

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_STRING_clear_free(tmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 147. [HIGH] Use-after-free pattern

**CWE-416** | `test/asn1_string_test.c` line 521

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 148. [HIGH] Use-after-free pattern

**CWE-416** | `test/asn1_string_test.c` line 549

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 149. [HIGH] Use-after-free pattern

**CWE-416** | `test/asn1_string_test.c` line 594

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(data);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 150. [HIGH] Use-after-free pattern

**CWE-416** | `test/asn1_string_test.c` line 595

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 151. [HIGH] Use-after-free pattern

**CWE-416** | `test/asn1_string_test.c` line 630

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 152. [HIGH] Use-after-free pattern

**CWE-416** | `test/asn1_string_test.c` line 655

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 153. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 102

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ssl3_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 154. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 131

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
dtls1_hm_fragment_free(frag);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 155. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 132

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
pitem_free(item);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 156. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 162

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(p_elem);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 157. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 196

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(recnum);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 158. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 246

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
dtls1_sent_msg_free(sent_msg);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 159. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 247

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
pitem_free(item);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 160. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 317

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ossl_dtls_listener_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 161. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 348

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ossl_dtls_rx_free(rx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 162. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 356

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ssl3_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 163. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 746

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 164. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 1052

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_ADDR_free(tmpclient);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 165. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 1136

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_ADDR_free(tmpclient);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 166. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 1137

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 167. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 1138

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(wbuf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 168. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 1331

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 169. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 1432

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
dtls_listener_connection_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 170. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 1507

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
dtls_listener_connection_free(conn_ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 171. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 1525

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
dtls_listener_connection_free(conn_ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 172. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 1550

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
dtls_listener_connection_free(conn_ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 173. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 1715

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MAC_CTX_free(mctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 174. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 1984

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
* including incoming_connections, notifier_cv, and OPENSSL_free(dl)
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 175. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 1992

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(dl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 176. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 2003

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
dtls_listener_connection_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 177. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 2020

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
dtls_listener_connection_free(conn);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 178. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 2264

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(ssl); /* Release the ref we just took */
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 179. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 2422

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(ssl); /* Release reference from phase 1 */
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 180. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 2441

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
dtls_listener_connection_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 181. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 2452

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
dtls_listener_connection_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 182. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 2473

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
dtls_listener_connection_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 183. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/d1_lib.c` line 2688

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
dtls_listener_connection_free(conn);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 184. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/d1_lib.c` line 741

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = OPENSSL_malloc(DTLS1_RT_HEADER_LENGTH + SSL3_RT_MAX_PLAIN_LENGTH);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 185. [HIGH] Missing NULL check after allocation

**CWE-476** | `ssl/d1_lib.c` line 744

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
wbuf = OPENSSL_malloc(DTLS1_RT_HEADER_LENGTH + SSL3_RT_MAX_PLAIN_LENGTH);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 186. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/asn1/tasn_fre.c` line 143

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
sk_ASN1_VALUE_free(sk);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 187. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/x509/t_req.c` line 34

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(b);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 188. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps_ui.c` line 175

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
UI_free(ui);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 189. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps_ui.c` line 213

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
UI_free(ui);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 190. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps_ui.c` line 214

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(prompt);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 191. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps_ui.c` line 147

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
void *vp = OPENSSL_malloc(sz);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 192. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps_ui.c` line 189

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buff = ui_malloc(bufsiz, "password buffer");
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 193. [HIGH] Use-after-free pattern

**CWE-416** | `test/tls13ccstest.c` line 313

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(sssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 194. [HIGH] Use-after-free pattern

**CWE-416** | `test/tls13ccstest.c` line 314

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(cssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 195. [HIGH] Use-after-free pattern

**CWE-416** | `test/tls13ccstest.c` line 335

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(s_to_c_fbio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 196. [HIGH] Use-after-free pattern

**CWE-416** | `test/tls13ccstest.c` line 336

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(c_to_s_fbio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 197. [HIGH] Use-after-free pattern

**CWE-416** | `test/tls13ccstest.c` line 480

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_SESSION_free(sess);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 198. [HIGH] Use-after-free pattern

**CWE-416** | `test/tls13ccstest.c` line 481

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(sssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 199. [HIGH] Use-after-free pattern

**CWE-416** | `test/tls13ccstest.c` line 482

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(cssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 200. [HIGH] Use-after-free pattern

**CWE-416** | `test/tls13ccstest.c` line 483

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_CTX_free(sctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 201. [HIGH] Use-after-free pattern

**CWE-416** | `test/tls13ccstest.c` line 484

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_CTX_free(cctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 202. [HIGH] Use-after-free pattern

**CWE-416** | `test/tls13ccstest.c` line 509

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_meth_free(method_watchccs);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 203. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/lms/lms_sig.c` line 25

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(sig);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 204. [CRITICAL] Format string vulnerability

**CWE-134** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 592

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(req_string, REQ_STRING_SZ, "GET /%s\r\n", req);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 205. [CRITICAL] Format string vulnerability

**CWE-134** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 596

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
snprintf(outfilename, REQ_STRING_SZ, "/downloads/%s", req);
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 206. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 161

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_ADDRINFO_free(res);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 207. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 183

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(bio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 208. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 441

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(session_bio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 209. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 545

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(outbiolist);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 210. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 546

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(outnames);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 211. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 547

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(poll_list);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 212. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 668

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(poll_list);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 213. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 669

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(outbiolist);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 214. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 825

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_ADDR_free(peer_addr);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 215. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 1040

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_ADDR_free(peer_addr);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 216. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 1041

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(reqnames);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 217. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 1042

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(req_bio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 218. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 1043

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(session_bio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 219. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 1048

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 220. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 1049

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 221. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 1050

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(outbiolist);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 222. [HIGH] Use-after-free pattern

**CWE-416** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 1051

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(poll_list);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 223. [HIGH] Missing NULL check after allocation

**CWE-476** | `test/quic-openssl-docker/hq-interop/quic-hq-interop.c` line 906

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
reqnames = OPENSSL_realloc(reqnames, read_offset + REQ_STRING_SZ);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 224. [CRITICAL] Format string vulnerability

**CWE-134** | `ms/uplink.c` line 66

User-controlled string passed as printf format argument. Attacker reads stack memory or overwrites return addresses via %n.

```
len = _sntprintf(msg, sizeof(msg) / sizeof(TCHAR),
```

**Fix:** Use a literal format string: printf("%s", user_input). Never pass user data as the format argument.
---

### 225. [HIGH] Use-after-free pattern

**CWE-416** | `demos/mac/gmac.c` line 139

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MAC_CTX_free(mctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 226. [HIGH] Use-after-free pattern

**CWE-416** | `demos/mac/gmac.c` line 140

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MAC_free(mac);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 227. [HIGH] Use-after-free pattern

**CWE-416** | `demos/mac/gmac.c` line 141

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_LIB_CTX_free(library_context);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 228. [HIGH] Use-after-free pattern

**CWE-416** | `demos/smime/smsign2.c` line 38

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(tbio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 229. [HIGH] Use-after-free pattern

**CWE-416** | `demos/smime/smsign2.c` line 90

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
PKCS7_free(p7);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 230. [HIGH] Use-after-free pattern

**CWE-416** | `demos/smime/smsign2.c` line 91

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(scert);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 231. [HIGH] Use-after-free pattern

**CWE-416** | `demos/smime/smsign2.c` line 92

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_free(skey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 232. [HIGH] Use-after-free pattern

**CWE-416** | `demos/smime/smsign2.c` line 93

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(scert2);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 233. [HIGH] Use-after-free pattern

**CWE-416** | `demos/smime/smsign2.c` line 94

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_free(skey2);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 234. [HIGH] Use-after-free pattern

**CWE-416** | `demos/smime/smsign2.c` line 95

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(in);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 235. [HIGH] Use-after-free pattern

**CWE-416** | `demos/smime/smsign2.c` line 96

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(out);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 236. [HIGH] Use-after-free pattern

**CWE-416** | `demos/smime/smsign2.c` line 97

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(tbio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 237. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/threads_common.c` line 202

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(mkey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 238. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/threads_common.c` line 369

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(mkey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 239. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ct/ct_sct_ctx.c` line 34

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(sctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 240. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ct/ct_sct_ctx.c` line 52

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(sctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 241. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ct/ct_sct_ctx.c` line 127

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_EXTENSION_free(new);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 242. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ct/ct_sct_ctx.c` line 195

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(pretmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 243. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ct/ct_sct_ctx.c` line 207

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(certder);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 244. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ct/ct_sct_ctx.c` line 208

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(preder);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 245. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ct/ct_sct_ctx.c` line 209

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(pretmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 246. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ct/ct_sct_ctx.c` line 251

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_free(sha256);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 247. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ct/ct_sct_ctx.c` line 252

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(md);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 248. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ct/ct_sct_ctx.c` line 253

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(der);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 249. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ct/ct_sct_ctx.c` line 275

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_free(pkey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 250. [HIGH] Missing NULL check after allocation

**CWE-476** | `crypto/ct/ct_sct_ctx.c` line 32

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
sctx->propq = OPENSSL_strdup(propq);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 251. [HIGH] Missing NULL check after allocation

**CWE-476** | `crypto/ct/ct_sct_ctx.c` line 229

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
md = OPENSSL_malloc(SHA256_DIGEST_LENGTH);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 252. [HIGH] Use-after-free pattern

**CWE-416** | `test/testutil/helper.c` line 50

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_TIME_free(timestamp_asn1);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 253. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 131

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(e);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 254. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 172

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(bn_p4);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 255. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 173

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(bn_p3);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 256. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 174

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(bn_p2);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 257. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 175

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(bn_p1);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 258. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 176

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(p);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 259. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 177

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 260. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 211

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(bn_p3);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 261. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 212

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(bn_p2);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 262. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 213

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(bn_p1);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 263. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 214

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(e);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 264. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 215

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(p);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 265. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 216

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 266. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 237

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(p);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 267. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 238

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(q);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 268. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 250

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(e);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 269. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 251

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(d);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 270. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 252

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(n);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 271. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 269

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
RSA_free(key);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 272. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 270

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 273. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 299

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(p);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 274. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 300

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(q);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 275. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 343

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(e);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 276. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 344

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
RSA_free(key);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 277. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 345

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 278. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 373

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(p);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 279. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 374

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(q);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 280. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 380

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(e);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 281. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 381

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
RSA_free(key);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 282. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 382

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 283. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 404

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(p);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 284. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 405

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(q);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 285. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 406

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(tmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 286. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 426

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(p);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 287. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 427

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(q);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 288. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 436

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(e);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 289. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 437

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(n);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 290. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 438

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(d);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 291. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 478

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
RSA_free(key);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 292. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 479

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 293. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 499

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
RSA_free(key);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 294. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 518

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(n);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 295. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 519

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(e);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 296. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 520

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(d);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 297. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 532

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
RSA_free(key);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 298. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 550

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(e);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 299. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 551

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(n);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 300. [HIGH] Use-after-free pattern

**CWE-416** | `test/rsa_sp800_56b_test.c` line 572

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
RSA_free(key);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 301. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `fuzz/test-corpus.c` line 148

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcpy(copy, pathname);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 302. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `fuzz/test-corpus.c` line 172

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcpy(pathname, arg);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 303. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `fuzz/test-corpus.c` line 179

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcpy(pathname + dirname_len, filename);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 304. [HIGH] Integer overflow in size calculation

**CWE-190** | `fuzz/test-corpus.c` line 138

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
char **paths = realloc(corpus_paths, capacity * sizeof(*paths));
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 305. [HIGH] Use-after-free pattern

**CWE-416** | `fuzz/test-corpus.c` line 119

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 306. [HIGH] Use-after-free pattern

**CWE-416** | `fuzz/test-corpus.c` line 188

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(pathname);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 307. [HIGH] Use-after-free pattern

**CWE-416** | `fuzz/test-corpus.c` line 284

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(corpus_paths);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 308. [HIGH] Missing NULL check after allocation

**CWE-476** | `fuzz/test-corpus.c` line 106

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = malloc(st.st_size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 309. [HIGH] Missing NULL check after allocation

**CWE-476** | `fuzz/test-corpus.c` line 138

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
char **paths = realloc(corpus_paths, capacity * sizeof(*paths));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 310. [HIGH] Missing NULL check after allocation

**CWE-476** | `fuzz/test-corpus.c` line 145

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
copy = malloc(strlen(pathname) + 1);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 311. [HIGH] Missing NULL check after allocation

**CWE-476** | `fuzz/test-corpus.c` line 169

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
pathname = malloc(PATH_MAX);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 312. [HIGH] Use-after-free pattern

**CWE-416** | `providers/implementations/signature/eddsa_sig.c` line 313

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ossl_ecx_key_free(edkey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 313. [HIGH] Use-after-free pattern

**CWE-416** | `providers/implementations/signature/eddsa_sig.c` line 517

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_CTX_free(hash_ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 314. [HIGH] Use-after-free pattern

**CWE-416** | `providers/implementations/signature/eddsa_sig.c` line 518

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_free(shake256);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 315. [HIGH] Use-after-free pattern

**CWE-416** | `providers/implementations/signature/eddsa_sig.c` line 783

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(peddsactx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 316. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ec/curve448/eddsa.c` line 45

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_CTX_free(hashctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 317. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ec/curve448/eddsa.c` line 46

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_free(shake256);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 318. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ec/curve448/eddsa.c` line 84

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_free(shake256);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 319. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ec/curve448/eddsa.c` line 88

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_free(shake256);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 320. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ec/curve448/eddsa.c` line 269

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_CTX_free(hashctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 321. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ec/curve448/eddsa.c` line 362

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_CTX_free(hashctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 322. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/ec/curve448/eddsa.c` line 366

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_CTX_free(hashctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 323. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/comp/c_brotli.c` line 41

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(address);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 324. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/comp/c_brotli.c` line 129

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(state);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 325. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/comp/c_brotli.c` line 140

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(state);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 326. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/comp/c_brotli.c` line 356

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
DSO_free(brotli_encode_dso);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 327. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/comp/c_brotli.c` line 358

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
DSO_free(brotli_decode_dso);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 328. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/comp/c_brotli.c` line 476

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 329. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/comp/c_brotli.c` line 493

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 330. [HIGH] Missing NULL check after allocation

**CWE-476** | `crypto/comp/c_brotli.c` line 522

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ctx->decode.buf = OPENSSL_malloc(ctx->decode.bufsize);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 331. [HIGH] Missing NULL check after allocation

**CWE-476** | `crypto/comp/c_brotli.c` line 596

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ctx->encode.buf = OPENSSL_malloc(ctx->encode.bufsize);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 332. [HIGH] Missing NULL check after allocation

**CWE-476** | `crypto/comp/c_brotli.c` line 743

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
tmp = OPENSSL_realloc(ctx->decode.buf, ibs);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 333. [HIGH] Missing NULL check after allocation

**CWE-476** | `crypto/comp/c_brotli.c` line 754

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
tmp = OPENSSL_realloc(ctx->encode.buf, obs);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 334. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_demux.c` line 89

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(demux);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 335. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/quic_demux.c` line 110

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(demux);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 336. [HIGH] Use-after-free pattern

**CWE-416** | `ssl/quic/cc_newreno.c` line 66

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(cc);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 337. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/evp/p_seal.c` line 70

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_CTX_free(pctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 338. [HIGH] Use-after-free pattern

**CWE-416** | `crypto/evp/p_seal.c` line 75

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_CTX_free(pctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 339. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `apps/lib/apps.c` line 3963

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcpy(outbuf, "key:");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 340. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `apps/lib/apps.c` line 3964

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(outbuf, val);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 341. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `apps/lib/apps.c` line 3979

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcpy(outbuf, "hexkey:");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 342. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `apps/lib/apps.c` line 3980

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(outbuf, val);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 343. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `apps/lib/apps.c` line 4016

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcpy(outbuf, "hexkey:");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 344. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `apps/lib/apps.c` line 4033

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcpy(outbuf, "key:");
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 345. [CRITICAL] Buffer overflow via unsafe string function

**CWE-120** | `apps/lib/apps.c` line 4034

strcpy/strcat/sprintf/gets without bounds checking. Stack or heap overflow leads to code execution.

```
strcat(outbuf, inbuf);
```

**Fix:** Use strncpy, strncat, snprintf with explicit size. Null-terminate manually. Prefer strlcpy/strlcat where available.
---

### 346. [HIGH] Integer overflow in size calculation

**CWE-190** | `apps/lib/apps.c` line 3149

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
tfrom = malloc(sizeof(*tfrom) * (flen + tlen));
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 347. [HIGH] Integer overflow in size calculation

**CWE-190** | `apps/lib/apps.c` line 3858

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
params = OPENSSL_calloc(sz + 1, sizeof(OSSL_PARAM));
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 348. [HIGH] Integer overflow in size calculation

**CWE-190** | `apps/lib/apps.c` line 3962

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
outbuf = app_malloc(strlen("key:") + strlen(val) + 1, "MACOPT KEYENV");
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 349. [HIGH] Integer overflow in size calculation

**CWE-190** | `apps/lib/apps.c` line 3978

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
outbuf = app_malloc(strlen("hexkey:") + strlen(val) + 1, "MACOPT KEYENVHEX");
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 350. [HIGH] Integer overflow in size calculation

**CWE-190** | `apps/lib/apps.c` line 4032

Arithmetic in allocator argument can overflow to a small value, causing under-allocation and subsequent heap overflow.

```
outbuf = app_malloc(strlen("key:") + strlen(inbuf) + 1, "MACOPT KEYSTDIN");
```

**Fix:** Validate sizes before arithmetic. Use calloc(n, size) for n*size. Check: if (n > SIZE_MAX / size) abort().
---

### 351. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 357

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NCONF_free(conf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 352. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 381

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(in);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 353. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 401

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NCONF_free(to_free);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 354. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 404

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NCONF_free(to_free);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 355. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 440

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NCONF_free(conf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 356. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 519

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(in);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 357. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 627

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_free(params);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 358. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 645

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(file_bio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 359. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 646

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_DECODER_CTX_free(dctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 360. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 722

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(subj);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 361. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 764

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
clear_free(pass_string);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 362. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 795

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_STACK_OF_X509_free(certs);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 363. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 799

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
clear_free(pass);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 364. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 805

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
clear_free(pass);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 365. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 806

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_STACK_OF_X509_free(certs);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 366. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 807

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_STACK_OF_X509_free(result);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 367. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 822

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_STORE_free(store);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 368. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 845

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_STORE_free(store);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 369. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 850

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_STACK_OF_X509_free(certs);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 370. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 858

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
clear_free(pass);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 371. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1026

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(bio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 372. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1106

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(cert);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 373. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1120

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_CRL_free(crl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 374. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1136

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_STORE_INFO_free(info);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 375. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1243

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(name);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 376. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1244

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(header);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 377. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1245

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 378. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1279

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_free(pkey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 379. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1293

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_free(cert);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 380. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1303

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
PKCS8_PRIV_KEY_INFO_free(p8);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 381. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1315

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_PKEY_free(pkey);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 382. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1319

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(name);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 383. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1320

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(header);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 384. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1321

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 385. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1323

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(in);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 386. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1530

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(buf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 387. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1639

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_STORE_free(store);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 388. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1713

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(ret);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 389. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1736

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(in);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 390. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1737

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_INTEGER_free(ai);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 391. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1792

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_INTEGER_free(ai);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 392. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1854

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BN_free(btmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 393. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1916

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(retdb);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 394. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1928

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
NCONF_free(dbattr_conf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 395. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1929

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
TXT_DB_free(tmpdb);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 396. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1987

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(out);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 397. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 1999

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(out);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 398. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2082

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(db);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 399. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2211

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(work);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 400. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2215

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_NAME_free(n);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 401. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2216

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(work);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 402. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2245

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(mem);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 403. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2253

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(mem);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 404. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2258

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BUF_MEM_free(bufm);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 405. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2344

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(stmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 406. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2369

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(stmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 407. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2407

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_ENCODER_CTX_free(ectx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 408. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2481

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(out);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 409. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2492

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(out);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 410. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2623

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_STORE_free(store);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 411. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2624

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_STORE_CTX_free(ctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 412. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2753

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_CTX_free(mctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 413. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2766

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_CTX_free(mctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 414. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2779

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_CTX_free(mctx);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 415. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2835

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(ret);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 416. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2858

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(urlptr);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 417. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2900

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
X509_CRL_free(crl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 418. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2934

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_OCTET_STRING_free(str);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 419. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 2975

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(bio); /* SSL BIO */
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 420. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3007

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
SSL_free(ssl);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 421. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3022

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(sbio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 422. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3032

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(info);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 423. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3079

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(mem);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 424. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3082

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(server);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 425. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3083

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(port);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 426. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3117

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(req_mem);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 427. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3119

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(rsp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 428. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3179

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
free(tfrom);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 429. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3439

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(b);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 430. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3459

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(b);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 431. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3674

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(fds);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 432. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3685

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(fds);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 433. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3808

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_TIME_free(tm);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 434. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3834

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
ASN1_TIME_free(tm);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 435. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3874

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(stmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 436. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3879

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(stmp);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 437. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3883

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
app_params_free(params);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 438. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 3894

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(params);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 439. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 4000

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(keybio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 440. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 4008

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(keybio);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 441. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 4029

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
clear_free(inbuf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 442. [HIGH] Use-after-free pattern

**CWE-416** | `apps/lib/apps.c` line 4035

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
clear_free(inbuf);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 443. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 185

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
result = OPENSSL_strdup(pass);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 444. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 227

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
return OPENSSL_strdup(arg);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 445. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 234

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
return OPENSSL_strdup(tmp);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 446. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 305

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
return OPENSSL_strdup(tpass);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 447. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 680

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
void *vp = OPENSSL_malloc(sz);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 448. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 1897

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
retdb = app_malloc(sizeof(*retdb), "new DB");
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 449. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 1912

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
retdb->dbfname = OPENSSL_strdup(dbfile);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 450. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 2133

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
work = OPENSSL_strdup(cp);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 451. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 2332

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
stmp = OPENSSL_strdup(value);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 452. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 2354

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
stmp = OPENSSL_strdup(value);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 453. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 2463

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
out = app_malloc(len + 1, "NPN buffer");
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 454. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 3149

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
tfrom = malloc(sizeof(*tfrom) * (flen + tlen));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 455. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 3858

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
params = OPENSSL_calloc(sz + 1, sizeof(OSSL_PARAM));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 456. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 3962

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
outbuf = app_malloc(strlen("key:") + strlen(val) + 1, "MACOPT KEYENV");
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 457. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 3978

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
outbuf = app_malloc(strlen("hexkey:") + strlen(val) + 1, "MACOPT KEYENVHEX");
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 458. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 3994

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
inbuf = app_malloc(MAX_KEY_SIZE, "MACOPT KEYFILE");
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 459. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 4015

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
outbuf = app_malloc(strlen("hexkey:") + total_read * 2 + 1, "MACOPT KEYFILE");
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 460. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 4032

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
outbuf = app_malloc(strlen("key:") + strlen(inbuf) + 1, "MACOPT KEYSTDIN");
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 461. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 4039

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
return OPENSSL_strdup(arg);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 462. [HIGH] Missing NULL check after allocation

**CWE-476** | `apps/lib/apps.c` line 4070

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
buf = app_malloc(MAX_KEY_SIZE, "get_str_from_file");
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 463. [HIGH] Use-after-free pattern

**CWE-416** | `demos/digest/BIO_f_md.c` line 123

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OPENSSL_free(digest_value);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 464. [HIGH] Use-after-free pattern

**CWE-416** | `demos/digest/BIO_f_md.c` line 124

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(input);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 465. [HIGH] Use-after-free pattern

**CWE-416** | `demos/digest/BIO_f_md.c` line 125

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
BIO_free(bio_digest);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 466. [HIGH] Use-after-free pattern

**CWE-416** | `demos/digest/BIO_f_md.c` line 126

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
EVP_MD_free(md);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 467. [HIGH] Use-after-free pattern

**CWE-416** | `demos/digest/BIO_f_md.c` line 127

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
OSSL_LIB_CTX_free(library_context);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 468. [HIGH] Missing NULL check after allocation

**CWE-476** | `demos/digest/BIO_f_md.c` line 80

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
digest_value = OPENSSL_malloc(digest_size);
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 469. [HIGH] Missing NULL check after allocation

**CWE-476** | `providers/implementations/ciphers/cipher_aes_xts.c` line 158

Return value of malloc/realloc not checked for NULL. On allocation failure the program dereferences NULL, causing a crash or exploitable condition.

```
ret = OPENSSL_malloc(sizeof(*ret));
```

**Fix:** Always check: ptr = malloc(n); if (!ptr) { handle_error(); return; }
---

### 470. [HIGH] Use-after-free pattern

**CWE-416** | `test/helpers/ssltestlib.h` line 44

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
void bio_f_tls_dump_filter_free(void);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 471. [HIGH] Use-after-free pattern

**CWE-416** | `test/helpers/ssltestlib.h` line 47

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
void bio_s_mempacket_test_free(void);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 472. [HIGH] Use-after-free pattern

**CWE-416** | `test/helpers/ssltestlib.h` line 50

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
void bio_s_always_retry_free(void);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 473. [HIGH] Use-after-free pattern

**CWE-416** | `test/helpers/ssltestlib.h` line 60

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
void bio_s_maybe_retry_free(void);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---

### 474. [HIGH] Use-after-free pattern

**CWE-416** | `test/helpers/ssltestlib.h` line 63

Freed pointer not immediately set to NULL. Dangling pointer reuse corrupts heap and can lead to code execution.

```
void bio_s_no_retry_zero_free(void);
```

**Fix:** Set pointer to NULL immediately after free(). Enable AddressSanitizer in CI: -fsanitize=address.
---
