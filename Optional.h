#pragma once
/*
*
*
* 参考:
* https://docs.oracle.com/javase/jp/8/docs/api/java/util/Optional.html
*/

template <class T>
class Optional {
private:
	T* pObj = nullptr;	// ポインタ型の値
	T obj = 0;			// ポインタ型以外の値

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

	// 指定された値がnullでない場合はその値を記述するOptionalを返し、それ以外の場合は空のOptionalを返します。
	static Optional<T> ofNullable(const T value) {
		Optional<T> optional(value);
		return optional;
	}

	// 空のOptionalを返します。
	static Optional<T> empty(void) {
		Optional<T> optional;
		return optional;
	}


	// このOptionalに値が存在する場合は値を返し、それ以外の場合はNoSuchElementExceptionをスローします。
	T get(void) const noexcept(false) {
		if (this->obj == 0 && this->pObj == nullptr) {
			//throw NoSuchElementException;
		}
		return this->obj;
	}

	// 値が存在しないtrueを返し、それ以外の場合はfalseを返す。
	bool isEmpty(void) const {
		return (this->obj == 0 && this->pObj == nullptr);
	}

	// 値が存在する場合はtrueを返し、それ以外の場合はfalseを返す。
	bool isPresent(void) {
		return (this->obj != 0 || this->pObj != nullptr);
	}

};


template <class T>
class Optional<T*> {
private:
	T* pObj = nullptr;	// ポインタ型の値
	T obj = 0;			// ポインタ型以外の値

public:
	explicit Optional(T* val) {
		this->pObj = val;
	}
	explicit Optional(void) = default;
	virtual ~Optional(void) {

	}

	// 指定された値がnullでない場合はその値を記述するOptionalを返し、それ以外の場合は空のOptionalを返します。
	static Optional<T*> ofNullable(const T* value) {
		if (value == nullptr) {
			return Optional::empty();
		}

		Optional<T*> optional(value);
		return optional;
	}

	// 空のOptionalを返します。
	static Optional<T*> empty(void) {
		Optional<T*> optional;
		return optional;
	}

	// このOptionalに値が存在する場合は値を返し、それ以外の場合はNoSuchElementExceptionをスローします。
	T* get(void) const noexcept(false) {
		if (this->obj == 0 && this->pObj == nullptr) {
			//throw NoSuchElementException;
		}
		return this->pObj;
	}

	// 値が存在しないtrueを返し、それ以外の場合はfalseを返す。
	bool isEmpty(void) const {
		return (this->obj == 0 && this->pObj == nullptr);
	}

	// 値が存在する場合はtrueを返し、それ以外の場合はfalseを返す。
	bool isPresent(void) {
		return (this->obj != 0 || this->pObj != nullptr);
	}

};


template <>
class Optional<std::string> {
private:
	char* pObj = nullptr;	// 値が入ったか判定用のポインタ
	std::string obj = "";	// 文字列

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

	// 指定された値がnullでない場合はその値を記述するOptionalを返し、それ以外の場合は空のOptionalを返します。
	static Optional<std::string> ofNullable(const std::string value) {
		Optional<std::string> optional(value);
		return optional;
	}

	// 空のOptionalを返します。
	static Optional<std::string> empty(void) {
		Optional<std::string> optional;
		return optional;
	}


	// このOptionalに値が存在する場合は値を返し、それ以外の場合はNoSuchElementExceptionをスローします。
	std::string get(void) const noexcept(false) {
		if (this->obj == "" && this->pObj == nullptr) {
			//throw NoSuchElementException;
		}
		return this->obj;
	}

	// 値が存在しないtrueを返し、それ以外の場合はfalseを返す。
	bool isEmpty(void) const {
		return (this->obj == "" && this->pObj == nullptr);
	}

	// 値が存在する場合はtrueを返し、それ以外の場合はfalseを返す。
	bool isPresent(void) {
		return (this->obj != "" || this->pObj != nullptr);
	}

};
