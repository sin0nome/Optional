#pragma once
/*
*
*
* �Q�l:
* https://docs.oracle.com/javase/jp/8/docs/api/java/util/Optional.html
*/

template <class T>
class Optional {
private:
	T* pObj = nullptr;	// �|�C���^�^�̒l
	T obj = 0;			// �|�C���^�^�ȊO�̒l

public:

	explicit Optional(const T val) {
		this->obj = val;
		this->pObj = new T;
	}
	explicit Optional(const T* val) {
		this->pObj = val;
	}
	explicit Optional(void) = default;
	virtual ~Optional(void) {
		if (this->pObj != nullptr) {
			delete this->pObj;
			this->pObj = nullptr;
		}
	}

	// �w�肳�ꂽ�l��null�łȂ��ꍇ�͂��̒l���L�q����Optional��Ԃ��A����ȊO�̏ꍇ�͋��Optional��Ԃ��܂��B
	static Optional<T> ofNullable(const T value) {
		Optional<T> optional(value);
		return optional;
	}
	static Optional<T*> ofNullable(const T* value) {
		if (value == nullptr) {
			return Optional::empty();
		}

		Optional<T*> optional(value);
		return optional;
	}

	// ���Optional��Ԃ��܂��B
	static Optional<T> empty(void) {
		Optional<T> optional;
		return optional;
	}


	// ����Optional�ɒl�����݂���ꍇ�͒l��Ԃ��A����ȊO�̏ꍇ��NoSuchElementException���X���[���܂��B
	Optional<T> get(void) const noexcept(false) {
		if (this->obj == 0 && this->pObj == nullptr) {
			//throw NoSuchElementException;
		}
		return this->pObj(this->obj);
	}

	// ����Optional�ɒl�����݂���ꍇ�͒l��Ԃ��A����ȊO�̏ꍇ��NoSuchElementException���X���[���܂��B
	Optional<T*> get(void) noexcept(false) {
		if (this->obj == 0 && this->pObj == nullptr) {
			//throw NoSuchElementException;
		}
		return Optional<T*>(this->pObj);
	}

	// �l�����݂��Ȃ�true��Ԃ��A����ȊO�̏ꍇ��false��Ԃ��B
	bool isEmpty(void) const {
		return (this->obj == 0 && this->pObj == nullptr);
	}

	// �l�����݂���ꍇ��true��Ԃ��A����ȊO�̏ꍇ��false��Ԃ��B
	bool isPresent(void) {
		return (this->obj != 0 || this->pObj != nullptr);
	}

};

