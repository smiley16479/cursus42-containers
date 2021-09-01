// https://quuxplusone.github.io/blog/2018/12/01/const-iterator-antipatterns/
// COMPRENDS RIEN EXEMPLE TROP TECHNIQUE POUR MOI
template<bool IsConst>
struct MyIterator 
{
    int *d_;
public:
/*     MyIterator(const MyIterator&) = default;  // REDUNDANT BUT GOOD STYLE

    template<bool IsConst_ = IsConst, class = std::enable_if_t<IsConst_>>
    MyIterator(const MyIterator<false>& rhs) : d_(rhs.d_) {}  // OK */
	 MyIterator(const MyIterator&) = default;  // REDUNDANT BUT GOOD STYLE
    MyIterator& operator=(const MyIterator&) = default;  // REDUNDANT BUT GOOD STYLE

    template<bool WasConst, class = std::enable_if_t<IsConst && !WasConst>>
    MyIterator(const MyIterator<WasConst>& rhs) : d_(rhs.d_) {}

    template<bool WasConst, class = std::enable_if_t<IsConst && !WasConst>>
    MyIterator& operator=(const MyIterator<WasConst>& rhs) { d_ = rhs.d_; return *this; }
};

using Iterator = MyIterator<false>;
using ConstIterator = MyIterator<true>;

struct MyContainer 
{
    using iterator = Iterator;
    using const_iterator = ConstIterator;

	// MyContainer();
    iterator begin();              // GOOD!
    const_iterator begin() const;  // GOOD!
};

int main(int argc, char const *argv[])
{
	MyContainer A;
	MyContainer::iterator a;
	MyContainer::const_iterator c;
	return 0;
}
