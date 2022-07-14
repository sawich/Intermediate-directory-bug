export module sc.streams.transforms.string.from_binary;

import sc.streams.concepts;

using namespace sc::streams::concepts;

export namespace sc::streams::transforms::string
{
	template <template<typename, typename, typename> typename TString, typename TStringSize, typename TStringElem, typename TStringTraits, typename TStringAlloc, template<typename, typename> typename TStream, typename TStreamElem, typename TStreamTraits> requires CString<TStream<TStreamElem, TStreamTraits>, TStreamElem, TStreamTraits, TString<TStringElem, TStringTraits, TStringAlloc>, TStringSize, TStringElem, TStringTraits, TStringAlloc>
	constexpr auto [[nodiscard]] from_binary(TStream<TStreamElem, TStreamTraits>& _stream)->TString<TStringElem, TStringTraits, TStringAlloc>
	{
		const TStringSize size{ from<TStringSize>(_stream) };

		TString<TStringElem, TStringTraits, TStringAlloc> string;
		_stream.read(reinterpret_cast<char*>(string.data()), size);

		return _stream;
	}
}
