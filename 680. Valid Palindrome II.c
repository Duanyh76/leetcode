bool core(char *s, int frontIndex, int tailIndex, bool canDel)
{
	if (frontIndex >= tailIndex)
		return true;
	if (s[frontIndex] == s[tailIndex])
		return core(s, frontIndex + 1, tailIndex - 1, canDel);
	if (canDel == false)
		return false;
	return core(s, frontIndex + 1, tailIndex, false) || core(s, frontIndex, tailIndex - 1, false);
}
bool validPalindrome(char* s) {
	int size = strlen(s);
	return core(s, 0, size - 1, true);
}