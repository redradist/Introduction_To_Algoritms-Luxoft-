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


/*
 1. Если ваша функция работает то можно вызывать рекурсивно
 2. Какждая функцци я должна начинаться с проверочного условия
 */
