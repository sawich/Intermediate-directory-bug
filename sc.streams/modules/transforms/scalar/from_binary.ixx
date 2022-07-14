export module sc.streams.transforms.scalar.from_binary;

import sc.streams.concepts;

using namespace sc::streams::concepts;

export namespace sc::streams::transforms::scalar
{
	template <typename T, size_t VSize = sizeof(T), template<typename, typename> typename TStream, typename TElem, typename TTraits> requires CScalar<T, VSize, TStream<TElem, TTraits>, TElem, TTraits>
	constexpr auto [[nodiscard]] from_binary(TStream<TElem, TTraits>& _stream)->T
	{
		constexpr size_t size = VSize;

		T value{};
		_stream.read(reinterpret_cast<TElem*>(&value), VSize);

		return value;
	}
}
