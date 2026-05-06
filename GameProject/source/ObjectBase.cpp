module ObjectBase;
import DxLibWrapper;

ObjectBase::ObjectBase() = default;

ObjectBase::ObjectBase(const TCHAR* fileName) {
    Load(fileName);
}

ObjectBase::~ObjectBase() {
    if (cgHandle != -1 && !cgHandleDeleteLock) {
        DW::DeleteGraph(cgHandle);
        cgHandle = -1;
    }
}

void ObjectBase::Init() {}

void ObjectBase::Load(const TCHAR* fileName) {
    cgHandle = DW::LoadGraph(fileName);
}

void ObjectBase::Process([[maybe_unused]] const int key, [[maybe_unused]] const int trigger) {}

void ObjectBase::Draw() {
    if (cgHandle != -1) {
        DW::DrawGraph(x, y, cgHandle, DW::DW_TRUE);
    }
}
