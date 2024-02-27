

#define ASSERT_POINTER(p)  { if (p == nullptr) { LOG("assert pointer failed"); return; } }
#define ASSERT_POINTER_R(p, ret)  { if (p == nullptr) { LOG("assert pointer failed"); return ret; } }
