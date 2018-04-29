class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> countPairedDomainList = new ArrayList<>();
        Map<String, Integer> domainCountMap = new HashMap<>();
        for (String cpdomain : cpdomains) {
            int spaceIndex = cpdomain.indexOf(" ");
            Integer count = Integer.parseInt(cpdomain.substring(0, spaceIndex));
            String domain = "." + cpdomain.substring(spaceIndex + 1, cpdomain.length());
            while (domain.contains(".")) {
                int dotIndex = domain.indexOf('.');
                domain = domain.substring(dotIndex + 1, domain.length());
                if (domainCountMap.containsKey(domain)) {
                    Integer newCount = count + domainCountMap.get(domain);
                    domainCountMap.remove(domain);
                    domainCountMap.put(domain, newCount);
                } else {
                    domainCountMap.put(domain, count);
                }
            }
        }
        for (String domain : domainCountMap.keySet()) {
            Integer count = domainCountMap.get(domain);
            String countPairedDomain = count.toString() + " " + domain;
            countPairedDomainList.add(countPairedDomain);
        }
        return countPairedDomainList;
    }

}