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

	// 指定された値がnullでない場合はその値を記述するOptionalを返し、それ以外の場合は空のOptionalを返します。
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

	// 空のOptionalを返します。
	static Optional<T> empty(void) {
		Optional<T> optional;
		return optional;
	}


	// このOptionalに値が存在する場合は値を返し、それ以外の場合はNoSuchElementExceptionをスローします。
	Optional<T> get(void) const noexcept(false) {
		if (this->obj == 0 && this->pObj == nullptr) {
			//throw NoSuchElementException;
		}
		return this->pObj(this->obj);
	}

	// このOptionalに値が存在する場合は値を返し、それ以外の場合はNoSuchElementExceptionをスローします。
	Optional<T*> get(void) noexcept(false) {
		if (this->obj == 0 && this->pObj == nullptr) {
			//throw NoSuchElementException;
		}
		return Optional<T*>(this->pObj);
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

