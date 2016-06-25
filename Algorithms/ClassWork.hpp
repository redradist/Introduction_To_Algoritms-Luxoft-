#pragma once

#include <assert.h>
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

/*
 1. Если ваша функция работает то можно вызывать рекурсивно
 2. Какждая функцци я должна начинаться с проверочного условия
 */
