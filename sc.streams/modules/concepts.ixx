export module sc.streams.concepts;

export namespace sc::streams::concepts
{
	template <typename TStream, typename TElem, typename TTraits>
	concept CStream = requires
	{
		std::convertible_to<TTraits, std::char_traits<TElem>>;
		std::derived_from<TStream, std::basic_istream<TElem, TTraits>>;
	};

	template <typename TValue, size_t VSize>
	concept CInconstantRegular = requires
	{
		std::regular<TValue>;
		
		//
		// For some var's we can use not full size.
		// Enum's at example
		//

		VSize <= sizeof(TValue);
		VSize != 0;
	};
	//
	template <typename T, size_t VSize, typename TStream, typename TElem, typename TTraits>
	concept CScalar = requires
	{
		CStream<TStream, TElem, TTraits>;
		CInconstantRegular<T, VSize>;
	};

	template<typename TString, typename TElem, typename TTraits, typename TAlloc, typename TSize>
	concept CSizedString = requires
	{
		std::integral<TSize>;
		std::derived_from<TString, std::basic_string<TElem, TTraits, TAlloc>>;
	};

	template <typename TString, typename TStringSize, typename TStringElem, typename TStringTraits, typename TStringAlloc, typename TStream, typename TStreamElem, typename TStreamTraits> 
	concept CString = requires 
	{
		CStream<TStream, TStreamElem, TStreamTraits>;
		CSizedString<TString, TStringSize, TStringElem, TStringTraits, TStringAlloc>;
	};
}
