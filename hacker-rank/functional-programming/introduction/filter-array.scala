object Solution extends App {
 
def f(delim:Int,arr:List[Int]):List[Int] = {
    def acc(delim:Int,arr:List[Int], result:List[Int]):List[Int] = arr match {
    case x :: xs => 
        if (x < delim)
          acc(delim, xs, result :+ x)
        else
          acc(delim, xs, result)
    case Nil => result
    }
    acc(delim, arr, List())
}
var lines = io.Source.stdin.getLines.toList
  println(f(lines(0).toInt,lines.map(_.trim).map(_.toInt)).map(_.toString).mkString("\n"))
}