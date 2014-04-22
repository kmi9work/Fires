require 'net/http'
require 'nokogiri'

print "Input first data, please (d.mm.yyyy | dd.mm.yyyy):"
# data1 = gets
data1 = '01.01.2011'
print "Input second data, please (d.mm.yyyy | dd.mm.yyyy):"
# data2 = gets
data2 = '02.02.2012'

uri = URI('http://rp5.ru/inc/f_archive.php')
req = Net::HTTP::Post.new(uri.path)

headers = {
  'X-Requested-With' => 'XMLHttpRequest',
  'Content-Type' => 'application/x-www-form-urlencoded',
  'Accept' => 'text/html, */*',
  'Accept-Encoding' => 'gzip, deflate',
  'Referer' => 'http://rp5.ru/%D0%90%D1%80%D1%85%D0%B8%D0%B2_%D0%BF%D0%BE%D0%B3%D0%BE%D0%B4%D1%8B_%D0%B2_%D0%98%D0%B3%D0%BD%D0%B0%D1%88%D0%B8%D0%BD%D0%BE',
  'User-Agent' => 'Opera/9.99 (Windows NT 5.1; U; pl) Presto/9.9.9',
  'Content-Type' => 'application/x-www-form-urlencoded',
  'Accept-Language' => 'ru-RU,ru;q=0.8,en-US;q=0.6,en;q=0.4'
}
parsed_data1 = data1.match(/(\d\d?)\.(\d\d)\.(\d\d\d\d)/)
parsed_data2 = data2.match(/(\d\d?)\.(\d\d)\.(\d\d\d\d)/)
data = {
  'wmo_id' => '30686',
  'f_ed0' => parsed_data1[1],
  'f_ed1' => parsed_data1[2],
  'f_ed2' => parsed_data1[3],
  'f_ed3' => '05',
  'f_ed4' => '03',
  'f_ed5' => '3',
  'f_ed6' => parsed_data2[1],
  'f_ed7' => parsed_data2[2],
  'f_ed8' => parsed_data2[3],
  'f_pe' => '1',
  'f_pe1' => '1',
  'lng_id' => '2'
}

# data.merge! request_to_data(URI::unescape(request.query))
headers.each { |key, value| req[key] = value }
# data.each { |key, value| req[key] = value }
req.set_form_data(data)
puts "-----------------"
p uri
puts "==========="
res = Net::HTTP.start(uri.host, uri.port) do |http|
  http.request(req)
end



# Output on the screen -> we should get either a 302 redirect (after a successful login) or an error page
# puts 'Code = ' + resp.code
#     puts 'Message = ' + resp.message
#     resp.each {|key, val| puts key + ' = ' + val}
p res.body
link = res.body.match(/<a href=(.+?)>/)[1]

puts link
uri1 = URI(link)
file = Net::HTTP.get(uri1)

gz = Zlib::GzipReader.new(StringIO.new(file))
puts gz.read
# 
# xml = Iconv.conv('UTF-8', 'CP1251', gz.read)
# puts xml

