class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> emailSet = new HashSet<>();
        for (String email : emails) {
            String localName = email.split("@")[0].split("\\+")[0].replace(".", "");
            String domainName = email.split("@")[1];
            String newEmail = localName + domainName;
            emailSet.add(newEmail);
        }
        return emailSet.size();
    }
}