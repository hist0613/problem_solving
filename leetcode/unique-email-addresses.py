class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        answer = set()
        for email in emails:
            local, domain = email.split('@')
            local = local.replace('.', '')
            local = local.split('+')[0]
            answer.add("{}@{}".format(local, domain))
        return len(answer)