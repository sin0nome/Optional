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

	// ���Optional��Ԃ��܂��B
	static Optional<T> empty(void) {
		Optional<T> optional;
		return optional;
	}


	// ����Optional�ɒl�����݂���ꍇ�͒l��Ԃ��A����ȊO�̏ꍇ��NoSuchElementException���X���[���܂��B
	T get(void) const noexcept(false) {
		if (this->obj == 0 && this->pObj == nullptr) {
			//throw NoSuchElementException;
		}
		return this->obj;
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


template <class T>
class Optional<T*> {
private:
	T* pObj = nullptr;	// �|�C���^�^�̒l
	T obj = 0;			// �|�C���^�^�ȊO�̒l

public:
	explicit Optional(T* val) {
		this->pObj = val;
	}
	explicit Optional(void) = default;
	virtual ~Optional(void) {

	}

	// �w�肳�ꂽ�l��null�łȂ��ꍇ�͂��̒l���L�q����Optional��Ԃ��A����ȊO�̏ꍇ�͋��Optional��Ԃ��܂��B
	static Optional<T*> ofNullable(const T* value) {
		if (value == nullptr) {
			return Optional::empty();
		}

		Optional<T*> optional(value);
		return optional;
	}

	// ���Optional��Ԃ��܂��B
	static Optional<T*> empty(void) {
		Optional<T*> optional;
		return optional;
	}

	// ����Optional�ɒl�����݂���ꍇ�͒l��Ԃ��A����ȊO�̏ꍇ��NoSuchElementException���X���[���܂��B
	T* get(void) const noexcept(false) {
		if (this->obj == 0 && this->pObj == nullptr) {
			//throw NoSuchElementException;
		}
		return this->pObj;
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


template <>
class Optional<std::string> {
private:
	char* pObj = nullptr;	// �l��������������p�̃|�C���^
	std::string obj = "";	// ������

public:
	explicit Optional(const std::string val) {
		this->obj = val;
		this->pObj = new char;
	}
	explicit Optional(void) = default;
	virtual ~Optional(void) {
		if (this->pObj != nullptr) {
			delete this->pObj;
			this->pObj = nullptr;
		}
	}

	// �w�肳�ꂽ�l��null�łȂ��ꍇ�͂��̒l���L�q����Optional��Ԃ��A����ȊO�̏ꍇ�͋��Optional��Ԃ��܂��B
	static Optional<std::string> ofNullable(const std::string value) {
		Optional<std::string> optional(value);
		return optional;
	}

	// ���Optional��Ԃ��܂��B
	static Optional<std::string> empty(void) {
		Optional<std::string> optional;
		return optional;
	}


	// ����Optional�ɒl�����݂���ꍇ�͒l��Ԃ��A����ȊO�̏ꍇ��NoSuchElementException���X���[���܂��B
	std::string get(void) const noexcept(false) {
		if (this->obj == "" && this->pObj == nullptr) {
			//throw NoSuchElementException;
		}
		return this->obj;
	}

	// �l�����݂��Ȃ�true��Ԃ��A����ȊO�̏ꍇ��false��Ԃ��B
	bool isEmpty(void) const {
		return (this->obj == "" && this->pObj == nullptr);
	}

	// �l�����݂���ꍇ��true��Ԃ��A����ȊO�̏ꍇ��false��Ԃ��B
	bool isPresent(void) {
		return (this->obj != "" || this->pObj != nullptr);
	}

};
