#pragma once

#include <assert.h>
#include <cstdlib>
#include <algorithm>
#include <vector>

namespace ClassSorting
{
	template<class TIter>
	TIter min_element(TIter b, TIter e)
	{
		TIter result = b;
		while (b < e)
		{
			if (*b < *result)
				result = b;
			++b;
		}
		return result;
	}

	template<class TIter>
	TIter max_element(TIter b, TIter e)
	{
		TIter result = b;
		while (b < e)
		{
			if (*b > *result)
				result = b;
			++b;
		}
		return result;
	}

	void sorting(int *A, int size) // Bubble sort
	{
		assert(A != nullptr);

		if (size != 0)
		{
			bool sorted;
			do
			{
				sorted = true;
				for (int i = 0; i < (size - 1); i++)
				{
					if (A[i] > A[i + 1])
					{
						sorted = false;
						int temp = A[i + 1];
						A[i + 1] = A[i];
						A[i] = temp;
					}
				}
			} while (!sorted);
		}
	}

	template<class TIter>
	void sorting_Bubble(TIter b, TIter e) // Bubble sortv alternative
	{
		for (TIter pivot = e; pivot != b; --pivot)
		{
			assert(std::is_sorted(pivot, e));
			for (TIter next_i = b + 1; next_i < pivot; ++next_i)
			{
				auto i = next_i - 1;
				assert(pivot == max_element(b, pivot + 1));
				if (*next_i < *i)
					std::swap(*i, *next_i);
				assert(pivot == max_element(b, pivot + 1));
			}
			assert(std::is_sorted(pivot, e));
		}
	}

	template<class TIter>
	void sort_naive(TIter b, TIter e)
	{
		for (int i = b; i < e; ++i)
		{
			for (int j = i + 1; j < e; ++j)
			{
				if (*j < *i)
					std::swap(*i, *j);
			}
		}
	}

	template<class TIter>
	void sort_selection(TIter b, TIter e) // Selection sort O(n^2)
	{
		for (TIter pivot = b; pivot < e; ++pivot)
		{
			assert(std::is_sorted(b, pivot));
			auto m = min_element(pivot, e);
			if (pivot != m)			   // O(1)
				std::swap(*pivot, *m); // O(1)
		}
	}

	template<class TIter>
	void sort_selection_fun(TIter b, TIter e) // Selection sort
	{
		for (TIter pivot = b; pivot < e; ++pivot)
		{
			assert(std::is_sorted(b, pivot));
			std::swap(*pivot, *min_element(pivot, e));
		}
	}

	// [b, e) = [sorted)
	// [b, e) = [b, p) [pivot, e)

	template<class TIter>
	void sort_insert(TIter b, TIter e) // Selection sort
	{
		for ()
		{
			assert(std::is_sorted(b, pivot));

			// insert pivot to [b, pivot)
			// [b, pivot) = 
			// [b, pivot)[v]
			for (TIter i = pivot; i != b; --i)
			{
				assert(std::is_sorted(b, i) && std::is_sorted(i, pivot + 1));
				auto next_i = i + 1;
				if (*next_i < *i)
					std::swap(*i, *next_i);
				else
					break;
				assert(std::is_sorted(b, i) && std::is_sorted(i, pivot + 1));
			}

			assert(std::is_sorted(b, pivot));
		}
	}

	template<typename TIter>
	void sort_Merge(TIter b, TIter e, TIter out) // implace merge sort
	{
		if ((e - b) > 1)
		{
			// [b, m)[m,e)
			// [b, m)[m,e)
			// [b, m)[m,e)
			TIter m = b + (e - b) / 2;
			sort_Merge(b, m, out);           // O(N/2^(k-m))
			sort_Merge(m, e, out + (m - b)); // O(N/2^(k-m))
			outer_Merge(b, m, m, e, out);    // O(N/2^m)
			std::copy(out, out + (e - b), b);
		}
		assert(std::is_sorted(b, e));
	}

	template<typename TIter>
	void outer_Sort_Merge(TIter src_b, TIter src_e, TIter dst_b) // outer merge sort
	{
		/*
		 How to realize outer Merge
		 */
	}

	template<typename TIter>
	void outer_Merge(TIter b0, TIter e0, TIter b1, TIter e1, TIter out)
	{
		TIter i0 = b0, i1 = b1;
		// [b0, i0) [i0, e0)
		// [b1, i1) [i1, e1)
		// [..., out)[out](out, ...)
		TIter b_out = out;
		while (i0 < e0 && i1 < e1) // O(N/2)
		{
			assert((i0 - b0) + (i1 - b1) == (out - b_out));
			assert(std::is_sorted(b_out, out));
			if (*i0 < *i1)
				*out = *i0++;
			else
				*out = *i1++;
			out++;
			assert(std::is_sorted(b_out, out));
			assert((i0 - b0) + (i1 - b1) == (out - b_out));
		}
		out = std::copy(i0, e0, out);
		out = std::copy(i1, e1, out);
		assert(std::is_sorted(b_out, out));
		assert((e0 - b0) + (e1 - b1) == (out - b_out));
	}

   template<typename TIter>
   void partition(TIter b, TIter pivot, TIter e)
   {
      assert(b <= pivot && pivot <= e);
      assert(b != e);

      // [b, pivot)[pivot][pivot, e)
      // [<x)[x][x<=)
      auto x = *pivot;
      while ()
      {
         // [partitioned) [unpartitioned)
         // [b, p)[p, bu) [bu, e)

         // [b, p)[p][p+1, bu) [bu] [bu+1, e)
         if (*bu >= *m)
         {
            // [b, p)[p, bu) [bu+1, e)
            bu++;
         }
         else
         {
            // [b, p)[p][p+1, bu) [bu] [bu+1, e)

         }
      }

      assert(b != pivot && *max(b, pivot) < *pivot);
      assert(*min(pivot, e) >= *pivot);
   }

   template<typename TIter>
   void quick_sort(TIter b, TIter e)
   {
      if (e - b <= 1)
         return;

      // TIter pivot = b;
      TIter pivot = partition(b, b + (e - b) / 2, e);
      // [b, p)[p][p+1, e)
      quick_sort(b, pivot);
      quick_sort(pivot+1, e);
   }

   // for low 2^8
   template<typename I>
   void counting_sort(std::vector<I> & v)
   {
      size_t counter_size = sizeof(I)*CHAR_BIT;
      size_t counters[counter_size] = { 0 };

      for (auto const &x : v)
      {
         ++counters[x];
      }

      size_t pos = 0;
      for (size_t i = 0; i < counter_size; ++i)
      {
         for (size_t j = 0; j < counters[i]; ++j)
         {
            v[pos] = i;
            pos++;
         }
      }
   }

   template<typename I>
   uint8_t radix_value(I x, size_t radix)
   {
      return static_cast<uint8_t>(x >> (radix*CHAR_BIT));
   }

   template<typename I>
   std::vector<size_t> compute_frequencies(std::vector<I> & v, size_t radix)
   {
      size_t counter_size = sizeof(I)*CHAR_BIT;
      std::vector<size_t> freq(counter_size, 0);
      for (auto const &x : v)
      {
         auto digit = radix_value(x, value);
         ++freq[digit];
      }
      return freq;
   }

   template<typename I>
   std::vector<size_t> cumulative_sums(std::vector<I> & freq)
   {
      std::vector<size_t> sums(freq.size()+1);
      std::copy(freq.begin(), freq.end(), std::back_inserter(sums))
      for (size_t i = 1; i < sums.size(); ++i)
      {
         sums[i] += sums[i-1];
      }
      return sums;
   }

   // for big s^pow, pow is big (O(N))
   template<typename I>
   void radix_sort(std::vector<I> & v)
   {
      std::vector<I> buff(v.size());

      auto radix_count = sizeof(T);
      for (size_t radix = 0; radix < radix_count; ++radix)  // O(1)
      {
         auto freq = compute_frequencies(v, radix);         // O(N)
         auto sums = cumulative_sums(freq);                 // O(1)

         for (auto x : v)                                   // O(N)
         {
            auto digit = radix_value(x, radix);             // O(1)
            auto index = sums[digit];                       // O(1)
            buff[index] = x;                                // O(1)
            ++sums[digit];                                  // O(1)
         }

         v.swap(buff);
      }
   }
}

namespace HeapSort {
   template<class V>
   V left(V i)
   {
      return 2 * i + 1;
   }

   template<class V>
   V right(V i)
   {
      return 2 * i + 2;
   }

   template<class V>
   V parent(V i)
   {
      assert(i > 0);
      return 2 * i + 1;
   }
   
   // Insert in leasts
   template <class T>
   void heapify(T a[], size_t i)
   {
      assert(is_heap(a, i));
      if (i == 0)
         return;
      auto p = parent(i);
      if (a[p] < a[i])
      {
         swap(a[p], a[i]);
         heapify(a, p);
      }
   }

   template <class T>
   void build_max_heap(std::vector<T>& A)
   {
      size_t heap_size = 1;
      while (heap_size < A.size())
      {
         heapify(A, heap_size);
         heap_size++;
      }
   }

   // Insert in head
   template <class T>
   void heapify_down(std::vector<T>& A, size_t i)
   {
      if (i >= A.size())
         return;
      auto max3 = compute_max_3(A, i, left(i), right(i));
      if (i != max3)
      {
         swap(a[max3], a[i]);
         heapify_down(A, max3);
      }
   }
   
   template <class T>
   size_t compute_max_3(std::vector<T>& A, size_t i, size_t left, size_t right)
   {
      /*
       Дописать compute_max_3 (a, b, c)
       */
   }

   template <class T>
   void build_max_heap_down(std::vector<T>& A, size_t i)
   {
      auto unprocessed_size = A.size() / 2;
      while (unprocessed_size > 0)
      {
         unprocessed_size--;
         heapify_down(A, unprocessed_size);
      }
   }

   template <class T>
   void heap_sort(std::vector<T>& A, size_t i)
   {
      build_max_heap_down(A);

      auto begin_sorted = A.size();
      while (begin_sorted > 0)
      {
         begin_sorted--;
         swap(A[begin_sorted], A[0]);
         auto heap_size = begin_sorted;
         heapify_down(A, 0, heap_size);
      }
   }
}

namespace DataStruct {

   template<typename T>
   class SortedVector {
      
   public:
      typedef std::vector<T>::iterator iterator;
      typedef std::vector<T>::const_iterator const_iterator;
      typedef T const & const_reference;
      typedef T & reference;

      SortedVector() = default;
      SortedVector(SortedVector const &) = default;
      SortedVector(SortedVector const &&) = default;
      SortedVector const & operator(SortedVector const &) = default;
      SortedVector const & operator(SortedVector const &&) = default;

      template<typename TIter>
      SortedVector(TIter first, TIter last) 
      {
         this->assign(first, last);
      }

      SortedVector(std::initializer_list<T> args)
      {
         std::vector<T> array { args };
         std::sort(array.begin(), array.end());
         mArray = array;
      }

      SortedVector(std::vector<T> & args)
      {
         std::sort(args.begin(), args.end());
         mArray = args;
      }

      template<typename TIter>
      void assign(TIter first, TIter last)
      {
         mArray.assign(first, last);
         std::sort(mArray.begin(), mArray.end());
         assert(valid_invarinant());
      }

      void pop_min() { mArray.pop_front(); }

      void pop_max() { mArray.pop_back(); }

      bool has(const_reference x) const {
         return std::binary_search(_xbegin(), end(), x);
      }

      void swap(SortedVector & vector) { mArray.swap(vector); }

      void reserve(size_t new_size) { mArray.reserve(new_size); }

      void remove(size_t const index)
      {
         mArray.erase();
      }

      void push(const_reference x)
      {
         assert(valid_invarinant());
         mArray.push_back(x);
         iterator it = mArray.end();
         iterator prev = it-1;
         while (it > mArray.begin())
         {
            assert(std::is_sorted(mArray.begin(), prev));
            assert(std::is_sorted(it, mArray.end());
            if (*it < *prev)
               std::iter_swap(it, prev);
            else
               break;
            it--;
            prev--;
            assert(std::is_sorted(mArray.begin(), prev));
            assert(std::is_sorted(it, mArray.end());
         }
         assert(valid_invarinant());
      }

      const_iterator remove(const_iterator it)
      {
         assert(valid_invarinant());
         return mArray.remove(it);
      }

      const_iterator remove(const_reference it)
      {
         assert(valid_invarinant());
         const_iterator it = this->lower_bound();
         it = mArray.remove(it);
         assert(valid_invarinant());
         return it;
      }

      bool valid_invarinant() const { return std::is_sorted(mArray); }

   public:
      
      const_reference peek_max() const { return mArray.front() }
      const_reference peek_min() const { return mArray.back() }
      const_reference peek_median() const { return *median(); }

      const_iterator begin() { return mArray.begin(); }
      const_iterator end() { return mArray.end(); }
      const_iterator median() { return begin() + (end() - begin())/2; }
      const_iterator lower_bound(const_reference value) const { return std::lower_bound(begin(), end(), value); }
      const_iterator upper_bound(const_reference value) const { return std::upper_bound(begin(), end(), value); }

      bool empty() const { return mArray.empty(); }
      size_t size() const { return mArray.size(); }
      size_t capacity() const { return mArray.capacity(); }

   private:
      std::vector<T>    mArray;
   }
      
}

namespace BiList {
   template<T> struct Node {
      Node<T>* prev;
      Node<T>* next;
   }

   template<T> struct RealNode : public Node<T> 
      RealNode(const T& data_,
               Node<T>* prev_ = nullptr,
               Node<T>* next_ = nullptr)
      : data(data_)
      , prev(prev_)
      , next(next_)
      { }

      T &data;
      Node<T>* prev;
      Node<T>* next;
   }

   template<T> struct DummyNode : public Node<T> {
      DummyNode()
      , prev(this)
      , next(this)
      { }

      DummyNode(Node<T>* prev_,
               Node<T>* next_)
      , prev(prev_)
      , next(next_)
      { }
      
      Node<T>* prev;
      Node<T>* next;
   }

   template<class T>
   void insert_after(Node<T>* node, const T& data) {
      assert(node != nullptr);

      _what->prev = _where->prev;
      _what->next = _where;

      _where->prev->next = _what;
      _where->prev = _what;

      assert(node->next == new_mode);
      assert(node == new_mode->prev);
   }

   template<class T>
   void insert_before(Node<T>* _where, Node<T>* _what) {
      assert(_where != nullptr);
      assert(_where->next != nullptr);
      assert(_what != nullptr);

      _what->prev = _where;
      _what->next = _where->next;

      _where->next->prev = _what;
      _where->next = _what;
      assert(_where != nullptr);
      assert(_what != nullptr);
   }

   template<class T>
   Node<T>* cut_out(Node<T>* what) {
      assert(what != nullptr);

      what->prev->next = what->next;
      what->next->prev = what->prev;
   }

   template<typename T> 
   struct iterator 
   {
      typedef size_t size_type;
      typedef T value_type;
      typedef T* pointer;
      typedef std::difference_type difference_type;

      iterator(const iterator& rhs) = default;
      iterator(const iterator&& rhs) = default;
      const iterator<T>& operator=(const iterator& rhs) = default;
      const iterator<T>&& operator=(const iterator&& rhs) = default;

   public:

      pointer operator->() 
      {
         assert(validate_invariant());
         return &(this->operator*());
      }

      reference operator*()
      {
         assert(validate_invariant());
         return static_cast<RealNode<T>*>(m_node)->data;
      }

      bool operator==(const iterator<T>& rhs) const
      {
         return m_node == rhs.m_node;
      }

      bool operator!=(const iterator<T>& rhs) const
      {
         return !(*this == rhs);
      }

      iterator& operator++() {
         return m_node = m_node->next;
      }

      iterator& operator++(int i) {
         auto node = m_node;
         m_node = m_node->next;
         return node;
      }

      iterator& operator--() {
         return m_node = m_node->prev;
      }

      iterator& operator--(int i) {
         auto node = m_node;
         m_node = m_node->prev;
         return node;
      }

   private:

      bool validate_invariant() const {
         return dynamic_cast<RealNode<T>*>(m_node) != nullptr;
      }

      friend class List<T>;
      iterator(Node<T>* node) : m_node(node) { }

      Node<T> *m_node;
   }
}

namespace ListOnAlgorithm {

   template<class T>
   class List {
   public:
      typedef size_t size_type;
      typedef T value_type;
      typedef T& reference;
      typedef const T& const_reference;
      typedef BiList::iterator<T> const_iterator;

   public:
      List()
      : m_pivot()
      , m_size(0)
      { 
         
      }

      List(const List& rhs)
      : List()
      {
         for (const auto& x : rhs)
         {
            this->push_back(x);
         }
      }
      
      const List<T>& operator=(const List& rhs) {
         if (this != &rhs)
            this->swap(List<T>(rhs));
         return *this;
      }

      void swap(List<T>& rhs) {
         swap(this->m_head, rhs.m_head);
         swap(this->m_tail, rhs.m_tail);
         swap(this->m_size, rhs.m_size);
      }

      ~List() {
         
      }

   public:

      // before c++11 standard size casts O(N) in c++11 O(1)
      size_type size() const { return m_size; }
      bool empty() const { return size() == 0; }

   public: // iterators

      iterator begin() { return iterator(m_pivot->next); }
      iterator end()   { return iterator(m_pivot); }

      iterator front() { return *begin(); }
      iterator back() { return *(--end()); }

   public:

      void push_front(const_reference data) {
         assert(validate_invariant());
         
         auto node = new RealNode<T>(data);
         insert_after(&m_pivot, node);
         m_size++;

         assert(validate_invariant());
      }

      void push_back(const_reference data) {
         assert(validate_invariant());

         auto node = new RealNode<T>(data);
         insert_before(&m_pivot, node);
         m_size++;

         assert(validate_invariant());
      }

      iterator insert(iterator it, const_reference data)
      {
         auto node = new RealNode<T>(data);
         insert_before(it.m_node, mode);
         m_size++;

         assert(validate_invariant());
         return iterator(node);
      }

      iterator erase(iterator it)
      {
         assert(it != end());

         auto node = it.m_node;
         auto node = BiList::cut_out(node);
         delete static_cast<RealNode<T>*>(node);
         m_size--;

         assert(validate_invariant());
         return iterator(node);
      }

   public:

      void reverse();
      void sort();
      void merge();
      void splice();

   private:

      bool validate_head() const { return m_head == nullptr || m_head->next == nullptr; }

      bool validate_tail() const { return m_tail == nullptr || m_tail->next == nullptr; }

      size_type compute_size() const
      {
         auto node = m_head;
         size_t result = 0;
         while (node)
         {
            node = node->next;
            result++;
         }
         return result;
      }

      bool validate_invariant() const
      {
         return 
            m_head->prev = nullptr &&
            m_tail->next == nullptr &&
            compute_size(m_head) == m_size;
      }

      BiList::DummyNode<T>    m_pivot;
      BiList::Node<T>         m_tail;
      size_type               m_size;
   };
}

/*
 1. Если ваша функция работает то можно вызывать рекурсивно
 2. Какждая функцци я должна начинаться с проверочного условия
 */
