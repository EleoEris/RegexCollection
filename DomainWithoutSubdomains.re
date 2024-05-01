(?:^\s*https?:\/\/)(?:[\w\d\-\.]*?)\.?((?:[\w\d\-]*)\.(?:(?:co|com|org|gov|net|edu|biz)\.[\w]{2}|[\w\d\-]*))(?:\/|$)

To note for use:
	- this accounts for double domain extensions, for example it will capture `google.co.uk` from `https://mail.google.co.uk/mail/u/0`, 
		but it only accounts for the first extensions I found most common: co|com|org|gov|net|edu|biz
		hypothetical example: let's say the extension of `https://myresume.website.codes.uk/` is `.codes.uk` the regex would wrongly capture `codes.uk`
		feel free to add (for example) `.codes` to the list if you don't think it would make the code more reliable
		but please note that it might break the code for a website such as `https://subdomain.codes.com` (if such site was valid)
	
	- you can easily change non-capturing groups to capturing ones by removing the initial `?:` from them


(?:								- non-capturing group - http(s) protocol
	^https?:\/\/				- start match at the beginning of the line, has to start with http:// or https://
)									- protocol end

(?:								- non-capturing - subdomain
	[\w\d\-\.]*?			- subdomain characters, use non-greedy `*` operator to avoid taking the proper domain
)									- subdomain end

\.?								- possible character `.` if subdomain present

(									- capturing group - proper domain with extension						
	(?:[\w\d\-]*)			- non-capturing - domain without extension
	\.							- character `.`
	(?:								- non-capturing - domain extension (possible double extension)
		(?:co|com|org|gov|net|edu|biz)		- non-capturing - possible first part of double extensions (ex. .co.uk)						
		\.							- character `.`
		[\w]{2}|[\w\d\-]*		- country code (any 2 characters)
	)									- domain extensions end
)									- proper domain capture end

(?:\/|$)					- end match at the end of the line or a `/`

