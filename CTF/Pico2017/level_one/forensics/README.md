# Digital Camouflage

Look into the data.pcap and filter for the POST packets.

Eventually the password is found as `cHJ2cUJaTnFZdw==`, which is Base64-encoded.

Decoding the password yields:

`prvqBZNqYw`

# Special Agent User

Look into the data.pcap and start digging into the Browser version.

There is a GET request where the client's User-Agent Header is revealed as 
`Mozilla/5.0 (Windows NT 10.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/40.0.2214.93 Safari/537.36\r\n`

Using the link they provide in the hint, the solution is found
`Chrome 40.0.2214`
